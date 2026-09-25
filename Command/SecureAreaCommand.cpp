#include "SecureAreaCommand.h"

//Function 1:
SecureAreaCommand::SecureAreaCommand(CampusArea* area, FacilitiesTeam* f) : area(area), wasAlreadyLocked(false), facilities(f){


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

    return facilities->releaseArea();
}

return area->unlock();

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