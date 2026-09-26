#ifndef RESPONSECOMPONENT_H
#define RESPONSECOMPONENT_H


#include <string>
#include <iostream>
#include <vector>

#include "CampusArea.h"

class IncidentMediator;


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
ResponseComponent(IncidentMediator* mediator);

//Function 1:
void setMediator(IncidentMediator* mediator);

//Function 2:
bool isAvailable() const;

//Function 3:
void setAvailability(bool available);

//Funtion 4:
virtual ~ResponseComponent();

virtual void onDispatch(CampusArea* location) {
        std::cout << "Team dispatched to " << location->name() << std::endl;
    }

};

#endif