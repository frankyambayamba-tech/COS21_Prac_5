#ifndef FACILITYTEAM_H
#define FACILITYTEAM_H


#include <string>
#include <iostream>
#include <vector>
#include "ResponseComponent.h"
#include "CampusArea.h"


using namespace std;

class FacilitiesTeam : public ResponseComponent{

private:
CampusArea* securedArea;

public:

//Function 1:
FacilitiesTeam();

//Function 2:
bool secureArea(CampusArea* area);

//Function 3:
bool isAreaSecured() const;

bool releaseArea();

};

#endif