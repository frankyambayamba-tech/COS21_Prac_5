#ifndef SECURITYTEAM_H
#define SECURITYTEAM_H


#include <string>
#include <iostream>
#include <vector>
#include "ResponseComponent.h"
#include "../Composite/CampusArea.h"


using namespace std;

class SecurityTeam : public ResponseComponent{

private:

bool injuriesFound;

CampusArea* lastLocation;

public:

//Function 1:
SecurityTeam();

//Function 2:
 void reportInjuries(bool found, CampusArea* location);

//Function 3:
bool hasInjuries() const;


//Function 4:
CampusArea* getLastLocation() const;

};

#endif