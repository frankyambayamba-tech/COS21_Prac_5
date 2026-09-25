#include "IssueAlertCommand.h"


//Function 1:
IssueAlertCommand::IssueAlertCommand(IncidentCoordinator* c, string& msg)
: IC(c), message(msg)
{}

//Function 2:
bool IssueAlertCommand::execute(){

    if(!canExecute()){

        return false;
    }

    return IC->handleAlert(message);

}

//Function 3:
bool IssueAlertCommand::undo(){

return false;
//You cannot not unsend an alert once its been issued

}

//Function 4:
bool IssueAlertCommand::canExecute() const{

    return IC != nullptr && !message.empty();

}

//Function 5:
string IssueAlertCommand::getDescription() const{


return "Issue alert command";

}

//Function 6:
IssueAlertCommand::~IssueAlertCommand(){



}