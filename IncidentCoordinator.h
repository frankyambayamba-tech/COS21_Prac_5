#ifndef INCIDENTCOORDINATOR_H
#define INCIDENTCOORDINATOR_H


#include <string>
#include <iostream>
#include <vector>
#include "IncidentMediator.h"
#include "SecurityTeam.h"
#include "MedicalTeam.h"
#include "FacilitiesTeam.h"



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
bool handleDispatch(ResponseComponent* team, CampusArea* location);

//Function 4:
bool handleAlert(const string& message);

};

#endif