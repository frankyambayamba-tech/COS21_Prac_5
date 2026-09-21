#ifndef MEDICALTEAM_H
#define MEDICALTEAM_H


#include <string>
#include <iostream>
#include <vector>
#include "ResponseComponent.h"
#include "../Composite/CampusArea.h"


using namespace std;

class MedicalTeam : public ResponseComponent{

public:

//Function 1:
MedicalTeam();

//Function 2:
bool respond(CampusArea* location);


};

#endif