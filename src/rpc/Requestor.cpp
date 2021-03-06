#include "Requestor.h"

#include "Node.h"
#include "ClientProxy.h"
#include "InstanceManager.h"
#include "InstanceContainer.h"
#include "RequestorManager.h"
#include "ClientRequestHandler.h"

#include <rpc/RemotingException.h>

#include <co/Log.h>
#include <co/IReflector.h>
#include <co/IComponent.h>
#include <co/IParameter.h>

namespace rpc {

Requestor::Requestor( RequestorManager* manager, ClientRequestHandler* handler, 
            const std::string& publicEndpoint ) : _connected( true ), _manager( manager ), 
                _handler( handler ), _instanceMan( manager->getInstanceManager() ),
                     _endpoint( handler->getEndpoint() ), _publicEndpoint( publicEndpoint )
{
}
    
void Requestor::disconnect()
{
    _connected = false;
}
    
Requestor::~Requestor()
{
    if( _connected )
        _manager->onRequestorDestroyed( _handler->getEndpoint() );
    
    delete _handler;
}

co::IObject* Requestor::requestNewInstance( const std::string& componentName )
{
    if( !_connected )
        CORAL_THROW( RemotingException, "Trying to request with the node stopped");
    
    std::string msg;
    _marshaller.marshalNew( _publicEndpoint, componentName, msg );
 
    _handler->handleSynchRequest( msg, msg );
    
    MessageType type = _demarshaller.demarshal( msg );
    
    if( type == EXCEPTION )
        raiseReturnedException( _demarshaller );
    
    co::int32 instanceID = _demarshaller.getIntReturn();
    
    co::IComponent* component = co::cast<co::IComponent>( co::getType( componentName ) );
    
    ClientProxy* cp = new ClientProxy( this, component, instanceID );
    _proxies.insert( std::pair<co::int32, ClientProxy*>( instanceID, cp ) );
    
    return cp;
}

co::IObject* Requestor::requestPublicInstance( const std::string& key, 
                                              const std::string& componentName )
{
    if( !_connected )
        CORAL_THROW( RemotingException, "Trying to request with the node stopped");
    
    std::string msg;
    _marshaller.marshalLookup( _publicEndpoint, key, componentName, msg );
    
    _handler->handleSynchRequest( msg, msg );
    
    MessageType type = _demarshaller.demarshal( msg );
    
    if( type == EXCEPTION )
        raiseReturnedException( _demarshaller );
    
    co::int32 instanceID = _demarshaller.getIntReturn();
    if( instanceID == -1 )
        return 0;
    
    // First, search if there isnt already a cp to the instanceID
    std::map<co::int32, ClientProxy*>::iterator it = _proxies.find( instanceID );
    if( it != _proxies.end() )
        return it->second;
    
    co::IComponent* component = co::cast<co::IComponent>( co::getType( componentName ) );
    
    ClientProxy* cp = new ClientProxy( this, component, instanceID );
    _proxies.insert( std::pair<co::int32, ClientProxy*>( instanceID, cp ) );

    return cp;
}

void Requestor::requestAsynchCall( MemberOwner& owner, co::IMethod* method,  
                                            co::Slice<co::Any> args )
{
    if( !_connected )
        CORAL_THROW( RemotingException, "Trying to request with the node stopped");
    
    InvocationDetails details( owner.instanceID, owner.facetID, method->getIndex(), 
                              owner.inheritanceDepth, false );
    ParameterPusher& pusher = _marshaller.beginInvocation( _publicEndpoint, details );
    
    pushParameters( method, args, pusher );
    
    std::string msg;
    _marshaller.marshalInvocation( msg );
    _handler->handleAsynchRequest( msg );    
}

void Requestor::requestSynchCall( MemberOwner& owner, co::IMethod* method, 
                                           co::Slice<co::Any> args, const co::Any& ret )
{
    if( !_connected )
        CORAL_THROW( RemotingException, "Trying to request with the node stopped");
    
    InvocationDetails details( owner.instanceID, owner.facetID, method->getIndex(), 
                              owner.inheritanceDepth, true );
    ParameterPusher& pusher = _marshaller.beginInvocation( _publicEndpoint, details );
    
    pushParameters( method, args, pusher );
    
    std::string msg;
    _marshaller.marshalInvocation( msg );

    _handler->handleSynchRequest( msg, msg );

	MessageType msgType = _demarshaller.demarshal( msg );
    
    if( msgType == EXCEPTION )
        raiseReturnedException( _demarshaller );
    
	ParameterPuller& puller = _demarshaller.getOutput();

	if( method->getReturnType() )
		getReturn( puller, method->getReturnType(), ret );

	co::TSlice<co::IParameter*> params = method->getParameters();
	for( int i = 0; i < params.getSize(); i++ )
	{
		if( params[i]->getIsOut() )
			getReturn( puller, params[i]->getType(), args[i] );
	}
}
    
void Requestor::requestSetField( MemberOwner& owner, co::IField* field, const co::Any arg )
{
    if( !_connected )
        CORAL_THROW( RemotingException, "Trying to request with the node stopped");
    
    InvocationDetails details( owner.instanceID, owner.facetID, field->getIndex(), 
                              owner.inheritanceDepth, false );
    ParameterPusher& pusher = _marshaller.beginInvocation( _publicEndpoint, details );
    
    co::IType* fieldType = field->getType();
    if( fieldType->getKind() != co::TK_INTERFACE )
    {
        pusher.pushValue( arg, fieldType );
    }
    else
    {
        ReferenceType refType;
        getProviderInfo( arg.get<co::IService*>(), refType );
        pusher.pushReference( refType );
    }
    
    std::string msg;
    _marshaller.marshalInvocation( msg );
    _handler->handleAsynchRequest( msg );
}
    
void Requestor::requestGetField( MemberOwner& owner, co::IField* field, const co::Any& ret )
{
    if( !_connected )
        CORAL_THROW( RemotingException, "Trying to request with the node stopped");
    
    InvocationDetails details( owner.instanceID, owner.facetID, field->getIndex(), 
                              owner.inheritanceDepth, true );
    _marshaller.beginInvocation( _publicEndpoint, details );
    
    std::string msg;
    _marshaller.marshalInvocation( msg );
    _handler->handleSynchRequest( msg, msg );
    
    MessageType msgType = _demarshaller.demarshal( msg );
    
    if( msgType == EXCEPTION )
        raiseReturnedException( _demarshaller );
    
	ParameterPuller& puller = _demarshaller.getOutput();

	getReturn( puller, field->getType(), ret );
}
    
void Requestor::requestLease( co::int32 instanceID, std::string lessee )
{
    if( !_connected )
        CORAL_THROW( RemotingException, "Trying to request with the node stopped");
    
    Marshaller marshaller; // cannot use the member instance (conflicts with other marshalling)
    std::string msg;
    marshaller.marshalLease( lessee, instanceID, msg );
    _handler->handleAsynchRequest( msg );
}
    
void Requestor::requestBarrierUp()
{
    if( !_connected )
        CORAL_THROW( RemotingException, "Trying to request with the node stopped");
    
    std::string msg;
    _marshaller.marshalBarrierUp( _publicEndpoint, msg );
    _handler->handleAsynchRequest( msg );
}
  
void Requestor::requestBarrierHit()
{
    if( !_connected )
        CORAL_THROW( RemotingException, "Trying to request with the node stopped");

    std::string msg;
    _marshaller.marshalBarrierHit( _publicEndpoint, msg );
    _handler->handleAsynchRequest( msg );
}
    
void Requestor::requestBarrierDown()
{
    if( !_connected )
        CORAL_THROW( RemotingException, "Trying to request with the node stopped");

    std::string msg;
    _marshaller.marshalBarrierDown( _publicEndpoint, msg );
    _handler->handleAsynchRequest( msg );
}
    
ClientProxy* Requestor::getOrCreateProxy( co::int32 instanceID, const std::string& componentName )
{
    std::map<co::int32, ClientProxy*>::iterator it = _proxies.find( instanceID );
    if( it != _proxies.end() )
        return it->second;

    co::IComponent* component = co::cast<co::IComponent>( co::getType( componentName ) );
    ClientProxy* cp = new ClientProxy( this, component, instanceID );
    _proxies.insert( std::pair<co::int32, ClientProxy*>( instanceID, cp ) );
    
    return cp;
}
    
void Requestor::pushParameters( co::IMethod* method, co::Slice<co::Any> args, 
                                   ParameterPusher& pusher )
{
    co::TSlice<co::IParameter*> params = method->getParameters();
    for( int i = 0; i < params.getSize(); i++ )
    {
		if( params[i]->getIsIn() )
		{
			co::IType* paramType = params[i]->getType();
			if( paramType->getKind() != co::TK_INTERFACE )
			{
				pusher.pushValue( args[i], paramType );
			}
			else
			{
				ReferenceType refType;
				getProviderInfo( args[i].get<co::IService*>(), refType );
				pusher.pushReference( refType );
			}
		}
    }
}

void Requestor::getProviderInfo( co::IService* param, ReferenceType& refType )
{
    co::IObject* provider = param->getProvider();
    
    refType.instanceType = provider->getComponent()->getFullName();

    refType.facetIdx = param->getFacet()->getIndex();
    
    if( !ClientProxy::isClientProxy( provider ) )
    {
        refType.instanceID = _instanceMan->addInstance( provider, _endpoint );
        refType.owner = OWNER_SENDER;
        refType.ownerEndpoint = _publicEndpoint;
    }
    else // is a remote object, so it provides the IInstanceInfo service
    {
        ClientProxy* providerCP = static_cast<ClientProxy*>( provider );
        
        refType.instanceID = providerCP->getInstanceId();
        
        Requestor* requestor = providerCP->getRequestor();
        
        if( requestor == this ) // Receiver
        {
            refType.owner = OWNER_RECEIVER;
            refType.ownerEndpoint = "";
        }
        else
        {
            CORAL_DLOG( INFO ) << "Passing a parameter that is a reference to a remote instance in : "
                        << requestor->getEndpoint() << " requesting a lease now.";
            
            requestor->requestLease( refType.instanceID, _endpoint );
            refType.owner = OWNER_ANOTHER;
            refType.ownerEndpoint = requestor->getEndpoint();
        }
    }
}

void Requestor::getReturn( ParameterPuller& puller, co::IType* type, const co::Any& ret )
{
    if( type->getKind() != co::TK_INTERFACE && type->getKind() != co::TK_EXCEPTION )
    {
        puller.pullValue( type, ret );
        return;
    }
    
    ReferenceType refType;
    
	puller.pullReference( refType );
    co::IObject* instance;
    switch( refType.owner )
    {
        case OWNER_RECEIVER:
        {
            instance = _instanceMan->getInstance( refType.instanceID )->getInstance();
            if( !instance )
                CORAL_THROW( rpc::RemotingException, "Server returned an invalid reference to a local instance" );
            break;
        }
        case OWNER_SENDER:
        case OWNER_ANOTHER:
            Requestor* req = _manager->getOrCreateRequestor( refType.ownerEndpoint );
            instance = req->getOrCreateProxy( refType.instanceID, refType.instanceType );
            break;
    }
    
    co::TSlice<co::IPort*> ports = instance->getComponent()->getFacets();
    
    co::IPort* port = ports[refType.facetIdx];
    co::IService* service = instance->getServiceAt( port );
    ret.put( service );
}
    
void Requestor::raiseReturnedException( Demarshaller& demarshaller )
{
    std::string exTypeName;
    std::string what;
    ExceptionType exType = demarshaller.getException( exTypeName, what );
    if( exType == EX_REMOTING )
    {
        // TODO try to resolve the problem if possible
        //if not resolved then:
        co::getType( exTypeName )->getReflector()->raise( what );
    }
    else
    {
        co::getType( exTypeName )->getReflector()->raise( what );
    }
}
    
} // namespace rpc