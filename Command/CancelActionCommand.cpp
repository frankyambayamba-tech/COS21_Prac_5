#include "CancelActionCommand.h"


//Function 1:
CancelActionCommand::CancelActionCommand(Command* prev)

: previousCommand(prev)
{}
//Function 2:
bool CancelActionCommand::execute(){

    if(!canExecute()){

        return false;
    }
    
    return previousCommand->undo();

}

//Function 3:
bool CancelActionCommand::undo(){

    if(!previousCommand){

        return false;
    }

    return previousCommand->execute();


}

//Function 4:
bool CancelActionCommand::canExecute() const{

    return previousCommand != nullptr;

}

//Function 5:
string CancelActionCommand::getDescription() const{

return "Cancel action command";

}

//Function 6:
CancelActionCommand::~CancelActionCommand(){


}