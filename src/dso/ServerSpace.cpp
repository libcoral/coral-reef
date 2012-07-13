/*
 * Calcium - Domain Model Framework
 * See copyright notice in LICENSE.md
 */

#include "ServerSpace_Base.h"

#include <co/Coral.h>
#include <co/RefPtr.h>
#include <co/IllegalArgumentException.h>
#include <co/IllegalStateException.h>

#include <ca/IUniverse.h>
#include <ca/IOException.h>
#include <ca/ISpace.h>
#include <ca/IModel.h>
#include <ca/IArchive.h>
#include <ca/INamed.h>
#include <ca/IGraphChanges.h>

#include <reef/rpc/INode.h>

#include <dso/ChangeSet.h>
#include <dso/IRemoteSpaceObserver.h>

#include <lua/IState.h>

#include <fstream>
#include <sstream>

#include <map>
#include <set>

namespace dso {

class ServerSpace : public ServerSpace_Base
{
public:
	ServerSpace()
	{
		_archiveObj = co::newInstance( "ca.LuaArchive" );
		_archiveObj->getService<ca::INamed>()->setName( "serverTmp.lua" );

		_archive = _archiveObj->getService<ca::IArchive>();

	}

	virtual ~ServerSpace()
	{

	}
	
	ca::ISpace* getSpace()
	{
		return _space.get();
	}
	
	void publishSpace( ca::ISpace* space, const std::string& key )
	{
		if( !_node.isValid() )
		{
			CORAL_THROW( co::IllegalStateException, "Server RPC node not set" );
		}
		
		if( space == NULL )
		{
			CORAL_THROW( co::IllegalArgumentException, "NULL space" );
		}

		if( key.empty() )
		{
			CORAL_THROW( co::IllegalArgumentException, "empty key" );
		}
		
		_space = space;
		_node->publishInstance( this, key );
		_space->addGraphObserver( this );
		initializeIds();
	}
	
	co::Range<co::int8 const> getPublishedSpaceData()
	{
		if( !_space.isValid() )
		{
			CORAL_THROW( co::IllegalStateException, "No space published" );
		}
		_archiveObj->setService( "model", _space->getModel() );
		_archive->save( _space->getRootObject() );

		std::ifstream ifs( "serverTmp.lua" );

		data.assign((std::istreambuf_iterator<char>(ifs)),
                 std::istreambuf_iterator<char>());
		ifs.close();
		return data;
	}

	void addRemoteSpaceObserver( dso::IRemoteSpaceObserver* observer )
	{
		_observers.push_back( observer );
	}

	void notifyRemoteChanges()
	{
		if( !_space.isValid() )
		{
			CORAL_THROW( co::IllegalStateException, "Space was not replicated from any server" );
		}

		if( _allChanges.empty() )
		{
			return;
		}

		const std::string& script = "dso.SpaceSyncServer";
		const std::string& function = "processAllSpaceChanges";

		std::vector<const co::Any> results;

		co::Any args[3];
		args[0].set<ca::ISpace*>( _space.get() );
		args[1].setArray( co::Any::AK_RefVector, co::getType( "ca.IGraphChanges" ), 0, &_allChanges );
		args[2].setArray( co::Any::AK_RefVector, co::getType( "dso.IRemoteSpaceObserver" ), 0, &_observers );
		
		co::getService<lua::IState>()->callFunction( script, function,
		co::Range<const co::Any>( args, CORAL_ARRAY_LENGTH( args ) ),
		results );
		
		_allChanges.clear();

	}
	
protected:

	void onGraphChanged( ca::IGraphChanges* changes )
	{
		_allChanges.push_back( changes );
	}

	void setServerNodeService( reef::rpc::INode* node )
	{
		_node = node;
	}
	
	reef::rpc::INode* getServerNodeService()
	{
		return _node.get();
	}
private:
	void initializeIds()
	{
		const std::string& script = "dso.SpaceSyncServer";
		const std::string& function = "initializeIds";

		std::vector<const co::Any> results;

		co::Any args[1];
		args[0].set<ca::ISpace*>( _space.get() );

		co::getService<lua::IState>()->callFunction( script, function,
			co::Range<const co::Any>( args, CORAL_ARRAY_LENGTH( args ) ),
			results );
	}
private:
	co::RefPtr<ca::ISpace> _space;
	co::RefPtr<reef::rpc::INode> _node;
	co::RefPtr<ca::IArchive> _archive;
	co::RefPtr<co::IObject> _archiveObj;
	co::RefVector<ca::IGraphChanges> _allChanges;
	
	co::RefVector<dso::IRemoteSpaceObserver> _observers;
	std::vector<co::int8> data;
};

CORAL_EXPORT_COMPONENT( ServerSpace, ServerSpace );

} // namespace dso