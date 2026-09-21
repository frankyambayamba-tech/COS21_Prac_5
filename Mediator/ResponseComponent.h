#ifndef RESPONSECOMPONENT_H
#define RESPONSECOMPONENT_H


#include <string>
#include <iostream>
#include <vector>
#include "IncidentMediator.h"


using namespace std;

class ResponseComponent{

protected:
IncidentMediator* mediator;

bool available;
//Function 4:
void changed();


public:

//Function 0:
ResponseComponent();
ResponseComponent(IncidentMediator* mediator, bool available);

//Function 1:
void setMediator(IncidentMediator* mediator);

//Function 2:
bool isAvailable() const;

//Function 3:
void setAvailability(bool available);

//Funtion 4:
virtual ~ResponseComponent();

};

#endif