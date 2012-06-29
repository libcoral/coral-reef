#include "ClientRequestHandler.h"

#include "ServerRequestHandler.h"

#include <reef/rpc/IActiveLink.h>

namespace reef {
namespace rpc {

ClientRequestHandler::ClientRequestHandler( IActiveLink* link, ServerRequestHandler* srh ) : 
                        _link( link ), _srh( srh ), _endpoint( link->getAddress() )
{}

// Low level API used by the ClientProxies
void ClientRequestHandler::handleAsynchRequest( const std::string& request )
{
    _link->send( request );
}

void ClientRequestHandler::handleSynchRequest( const std::string& request, std::string& ret )
{
    _link->send( request );
    
    // The Wait for the reply still keeps updating the server
    while( !_link->receiveReply( ret ) )
        _srh->react();
}

}
}