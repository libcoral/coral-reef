#include "ZMQTransport.h"

#include "ZMQActiveLink.h"
#include "ZMQPassiveLink.h"

#include <reef/rpc/IActiveLink.h>
#include <reef/rpc/IPassiveLink.h>

namespace zmq {
    
ZMQTransport::ZMQTransport()
{
    // empty constructor
}

ZMQTransport::~ZMQTransport()
{
    // empty destructor
}

// ------ reef.ITransport Methods ------ //

reef::rpc::IPassiveLink* ZMQTransport::bind( const std::string& addressToListen )
{
    ZMQPassiveLink* link = new ZMQPassiveLink();
    link->bind( addressToListen );
    return link;
}

reef::rpc::IActiveLink* ZMQTransport::connect( const std::string& addressToConnect )
{
    // Tries to find an existing ActiveLink and returns it
    ActiveLinks::iterator it = _activeLinks.find( addressToConnect );
    if( it != _activeLinks.end() )
    {
        return it->second;
    }
    
    // Creates a new ALink            
    return createActiveLink( addressToConnect );
}

void ZMQTransport::onLinkDestructor( const std::string& address )
{
    // remove the entry in the connections map
    ActiveLinks::iterator it = _activeLinks.find( address );
    if( it != _activeLinks.end() )
    {
        _activeLinks.erase( it );
    }
}

reef::rpc::IActiveLink* ZMQTransport::createActiveLink( const std::string& address )
{
    ZMQActiveLink* link = new ZMQActiveLink( this );
    link->connect( address );
    _activeLinks.insert( std::pair<std::string, reef::rpc::IActiveLink*>( address, link ) );
    return link;
}
     
CORAL_EXPORT_COMPONENT( ZMQTransport, ZMQTransport );
    
} // namespace reef
