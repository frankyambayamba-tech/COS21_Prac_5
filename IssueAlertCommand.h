#ifndef ISSUEALERTCOMMAND_H
#define ISSUEALERTCOMMAND_H

#include "Command.h"
#include "IncidentCoordinator.h"
#include <string>
#include <iostream>
#include <vector>


using namespace std;

class IssueAlertCommand : public Command{

private:

IncidentCoordinator* IC;

string message;

public:

//Function 1:
IssueAlertCommand(IncidentCoordinator* IC, string& message);

//Function 2:
bool execute();

//Function 3:
bool undo();

//Function 4:
bool canExecute() const;

//Function 5:
string getDescription() const;

//Function 6:
virtual ~IssueAlertCommand();


};

#endif