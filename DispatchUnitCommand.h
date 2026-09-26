#ifndef DISPATCHUNITCOMMAND_H
#define DISPATCHUNITCOMMAND_H

#include "Command.h"
#include "IncidentCoordinator.h"
#include "ResponseComponent.h"
#include <string>
#include <iostream>
#include <vector>


using namespace std;

class DispatchUnitCommand : public Command{

private:

IncidentCoordinator* IC;

ResponseComponent* team;

string location;


public:

//Function 1:
DispatchUnitCommand(IncidentCoordinator* IC, ResponseComponent* team, string& location);

//Function 2:
bool execute();

//Function 3:
bool undo();

//Function 4:
bool canExecute() const;

//Function 5:
string getDescription() const;

//Function 6:
virtual ~DispatchUnitCommand();

};

#endif