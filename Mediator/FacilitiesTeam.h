#ifndef FACILITYTEAM_H
#define FACILITYTEAM_H


#include <string>
#include <iostream>
#include <vector>
#include "ResponseComponent.h"


using namespace std;

class FacilitiesTeam : public ResponseComponent{

private:
bool areaSecured;

public:

//Function 1:
FacilitiesTeam(bool areaSecured);

//Function 2:
bool secureArea(CampusArea* area);

//Function 3:
bool isAreaSecured() const;

};

#endif