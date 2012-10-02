#include "ClientRequestHandler.h"

#include "ServerRequestHandler.h"

#include <rpc/IConnector.h>
#include <rpc/RemotingException.h>

#include <ctime>
#include <sstream>

namespace rpc {

ClientRequestHandler::ClientRequestHandler( IConnector* link, ServerRequestHandler* srh ) : 
                        _link( link ), _srh( srh ), _endpoint( link->getAddress() ), _timeout( 100000 )
{}

// Low level API used by the ClientProxies
void ClientRequestHandler::handleAsynchRequest( const std::string& request )
{
    _link->send( request );
}

void ClientRequestHandler::handleSynchRequest( const std::string& request, std::string& ret )
{
    _link->send( request );
    
    // Begin counting for timeout
    time_t tstart = time(0);
    
    // The Wait for the reply still keeps updating the server
    while( !_link->receiveReply( ret ) )
    {
        _srh->react();
        
        if( time( 0 ) - tstart > _timeout )
            CORAL_THROW( RemotingException, "Reply receiving timeout" );
    }
}

} // namespace rpc