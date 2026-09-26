#include "FacilitiesTeam.h"

//Function 1:
FacilitiesTeam::FacilitiesTeam(){

    securedArea = nullptr;


}

//Function 2:
bool FacilitiesTeam::secureArea(CampusArea* area){

if(!area){

    return false;
}

 area->lockDown();

bool locked = area->isSecured();

if(locked){

    securedArea = area;

    changed();
}

return locked;

}

 bool FacilitiesTeam::releaseArea(){

        if (!securedArea){
            
            return false;
        }

        securedArea->unlock();

        bool unlocked = securedArea->isSecured();

        if (unlocked) securedArea = nullptr;

        return unlocked;
    }


//Function 3:
bool FacilitiesTeam::isAreaSecured() const{

 return securedArea != nullptr;

}