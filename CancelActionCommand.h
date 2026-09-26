#ifndef CANCELACTIONCOMMAND_H
#define CANCELACTIONCOMMAND_H

#include "Command.h"
#include "IncidentCoordinator.h"
#include <string>
#include <iostream>
#include <vector>


using namespace std;

class CancelActionCommand : public Command{

private:

Command* previousCommand;

public:

//Function 1:
CancelActionCommand(Command* previousCommand);

//Function 2:
bool execute();

//Function 3:
bool undo();

//Function 4:
bool canExecute() const;

//Function 5:
string getDescription() const;

//Function 6:
virtual ~CancelActionCommand();

};

#endif