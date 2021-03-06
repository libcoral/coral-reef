#include "LeaseManager.h"

#include <rpc/RemotingException.h>

#include <sstream>

namespace rpc {

LeaseManager::~LeaseManager()
{
    std::map<std::string, Lessee*>::iterator lesseeIt = _lessees.begin();
    
    for( ; lesseeIt != _lessees.end(); lesseeIt++ )
    {
        delete lesseeIt->second;
    }
    
    std::map<co::int32, Lessor*>::iterator lessorIt = _lessors.begin();
    
    for( ; lessorIt != _lessors.end(); lessorIt++ )
    {
        delete lessorIt->second;
    }
}
    
void LeaseManager::addLease( co::int32 lessorID, const std::string lesseeEndpoint )
{
    Lessee* lessee = findLessee( lesseeEndpoint );
    
    if( !lessee )
    {
        lessee = new Lessee();
        _lessees.insert( std::pair<std::string, Lessee*>( lesseeEndpoint, lessee ) );
    }
    
    lessee->addLease( lessorID );
    
    std::map<co::int32, Lessor*>::iterator it = _lessors.find( lessorID );
    
    Lessor* lessor;
    if( it != _lessors.end() )
    {
        lessor = it->second;
    }
    else
    {
        lessor = new Lessor();
        _lessors.insert( std::pair<co::int32, Lessor*>( lessorID, lessor ) );
    }
    
    lessor->addLease( lessee );
}

bool LeaseManager::removeLease( co::int32 lessorID, const std::string lesseeEndpoint )
{
    std::map<std::string, Lessee*>::iterator lesseeIt = _lessees.find( lesseeEndpoint );
    if( lesseeIt == _lessees.end() )
		CORAL_THROW( RemotingException, "The lessee has 0 leases to cancel" )
    
    // Remove the reference to the lessor from the lessee, and if empty, remove the lessee
    Lessee* lessee = lesseeIt->second;
    
    if( !lessee->removeLease( lessorID ) )
        CORAL_THROW( RemotingException, "The lessee has lease for " << lessorID );
    
    if( !lessee->hasLeases() )
    {
        _lessees.erase( lesseeIt );
        delete lessee;
    }
    
    // Find the lessor, remove the reference to the lessee from it
    std::map<co::int32, Lessor*>::iterator lessorIt = _lessors.find( lessorID );
    assert( lessorIt != _lessors.end() ); 
    
    Lessor* lessor = lessorIt->second;
    
    if( !lessor->removeLease( lessee ) )
    {
        CORAL_THROW( RemotingException, lessor << " requested a removal of an inexistant lease for id: "  
                    << lessee )
    }
    
    // Check if lessor is empty, if true, remove the lessor and return true
    if( !lessor->numLeases() )
    {
        _lessors.erase( lessorIt );
        delete lessor;    
        return true;
    }
    
    return false;
}
    
co::int32 LeaseManager::numLeases( co::int32 lessorID )
{
    std::map<co::int32, Lessor*>::iterator lessorIt = _lessors.find( lessorID );
    if( lessorIt != _lessors.end() )
        return lessorIt->second->numLeases();
    
    return 0;
}
    
Lessee* LeaseManager::findLessee( const std::string& lesseeEnpoint )
{
    std::map<std::string, Lessee*>::iterator it = _lessees.find( lesseeEnpoint );
    return  it == _lessees.end() ? 0: it->second;
}
} // namespace rpc
