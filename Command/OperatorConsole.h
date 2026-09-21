#ifndef OPERATORCONSOLE_H
#define OPERATORCONSOLE_H


#include <string>
#include <iostream>
#include <vector>
#include "Command.h"


using namespace std;

class OperatorConsole{

private:

vector<Command*> history;

public:

//Function 2:
bool submit(Command* command);

//Function 3:
bool cancelList();

//Function 4:
void printHistory() const;

//Function 5:
virtual ~OperatorConsole();

};

#endif