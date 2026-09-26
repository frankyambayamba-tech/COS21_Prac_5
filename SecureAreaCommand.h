#ifndef SECUREAREACOMMAND_H
#define SECUREAREACOMMAND_H

#include "Command.h"
#include "IncidentCoordinator.h"
#include "CampusArea.h"
#include <string>
#include <iostream>
#include <vector>


using namespace std;

class SecureAreaCommand : public Command{

private:

FacilitiesTeam* facilities;

CampusArea* area;

bool wasAlreadyLocked;

public:

//Function 1:
SecureAreaCommand(CampusArea* area, FacilitiesTeam* f);

//Function 2:
bool execute();

//Function 3:
bool undo();

//Function 4:
bool canExecute() const;

//Function 5:
string getDescription() const;

//Function 6:
virtual ~SecureAreaCommand();


};

#endif