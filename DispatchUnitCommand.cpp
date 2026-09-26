#include "DispatchUnitCommand.h"


//Function 1:
DispatchUnitCommand::DispatchUnitCommand(IncidentCoordinator* c, ResponseComponent* t, CampusArea* l)
: IC(c), team(t), location(l)
{}

//Function 2:
bool DispatchUnitCommand::execute(){

    if(!canExecute()){

        return false;
    }

    return IC->handleDispatch(team,location);

}

//Function 3:
bool DispatchUnitCommand::undo(){

if(!team){

    return false;
}

team->setAvailability(true);

return true;

}

//Function 4:
bool DispatchUnitCommand::canExecute() const{

return IC && team && team->isAvailable();

}

//Function 5:
string DispatchUnitCommand::getDescription() const{

return "Dispatch unit command";

}

//Function 6:
DispatchUnitCommand::~DispatchUnitCommand(){



}