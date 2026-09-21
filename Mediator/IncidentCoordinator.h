#ifndef INCIDENTCOORDINATOR_H
#define INCIDENTCOORDINATOR_H


#include <string>
#include <iostream>
#include <vector>
#include "IncidentMediator.h"


using namespace std;

class IncidentCoordinator : public IncidentMediator{

private:

vector<ResponseComponent*> responseList;

public:

//Function 1:
void notify(ResponseComponent* colleague);

//Function 2:
void registerComponent(ResponseComponent* component);

//Function 3:
bool handleDispatch(ResponseComponent* team, string location);

//Function 4:
bool handleAlert(string& message);

};

#endif