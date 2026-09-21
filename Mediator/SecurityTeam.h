#ifndef SECURITYTEAM_H
#define SECURITYTEAM_H


#include <string>
#include <iostream>
#include <vector>
#include "ResponseComponent.h"


using namespace std;

class SecurityTeam : public ResponseComponent{

private:

bool injuriesFound;

public:

//Function 1:
SecurityTeam(bool injuriesFound);

//Function 2:
void reportInjuries(bool found);

//Function 3:
bool hasInjuries() const;


};

#endif