#ifndef COMMAND_H
#define COMMAND_H


#include <string>
#include <iostream>
#include <vector>


using namespace std;

class Command{

public:
//Function 1;
virtual bool execute() = 0;

//Function 2:
virtual bool undo() = 0;

//Function 3:
virtual bool canExecute() const = 0;

//Function 4:
//Describes what the command did
virtual string getDescription() const = 0;

//Function 5:
virtual ~Command();

};

#endif