#include "SecurityTeam.h"


//Function 1:
SecurityTeam::SecurityTeam()
{
    injuriesFound = false;

    lastLocation = nullptr;
}

//Function 2:
void SecurityTeam::reportInjuries(bool found, CampusArea* location){

    injuriesFound = found;

    lastLocation = location;

    changed();

}

//Function 3:
bool SecurityTeam::hasInjuries() const{

return injuriesFound;

}

//Function 4:
CampusArea* SecurityTeam::getLastLocation() const{

return lastLocation;

}