#include "OperatorConsole.h"


//Function 2:
bool OperatorConsole::submit(Command* command){

    if(!command || !command->canExecute()){

        return false;
    }

    bool result = command->execute();

    if(result){

        history.push_back(command);
    }

    return result;


}

//Function 3:
bool OperatorConsole::cancelLast(){

if(history.empty()){

    return false;
}

Command* last = history.back();

bool result = last->undo();

if(result){

    history.pop_back();

    delete last;
}

return result;

}

//Function 4:
void OperatorConsole::printHistory() const{

    for(Command* command : history){

        cout<< command->getDescription() <<endl;
    }
}

//Function 5:
OperatorConsole::~OperatorConsole(){

    for(Command* command : history){

        delete command;
    }



}
