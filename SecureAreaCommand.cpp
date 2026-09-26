#include "SecureAreaCommand.h"

//Function 1:
SecureAreaCommand::SecureAreaCommand(CampusArea* area, FacilitiesTeam* f) : facilities(f), area(area), wasAlreadyLocked(false){


}

//Function 2:
bool SecureAreaCommand::execute(){

    if(!canExecute()){

        return false;
    }

    //Check for this function
    wasAlreadyLocked = area->isSecured();

    if(wasAlreadyLocked == true){

        return true;
    }

    return facilities->releaseArea();

}

//Function 3:
bool SecureAreaCommand::undo(){

if(!facilities || wasAlreadyLocked){
    if(facilities){
        return facilities->releaseArea();
    }

    return false;
}

area->unlock();
return true;

}

//Function 4:
bool SecureAreaCommand::canExecute() const{

return area && facilities;

}

//Function 5:
string SecureAreaCommand::getDescription() const{

return "Secure area command";
}

//Function 6:
SecureAreaCommand::~SecureAreaCommand(){


}

//SecureAreaCommand → FacilitiesTeam → CampusArea