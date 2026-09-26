#ifndef INCIDENTMEDIATOR_H
#define INCIDENTMEDIATOR_H


#include <string>
#include <iostream>
#include <vector>
#include "ResponseComponent.h"


using namespace std;

// enum class IncidentEvent{

// AreaSecured,

// UnitDispatched,

// AlertIssued,

// ActionCancelled

// };

class IncidentMediator{

public:

//Function 1:
virtual void notify(ResponseComponent* colleague) = 0;

//Function 2:
virtual void registerComponent(ResponseComponent* component) = 0;

//Function 3:
virtual ~IncidentMediator();


};

#endif