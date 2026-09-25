#include "LegacyAccessSystem.h"
#include <iostream>

int LegacyAccessSystem :: engageLock (int hallCode) {
    
    std::cout << " LegacyAccessSystem engageLock : " << hallCode;

    return 0;
}

int LegacyAccessSystem :: disengageLock (int hallCode) {

    std::cout << "LegacyAccessSystem disengageLock : " << hallCode;

    return 0;
}

int LegacyAccessSystem :: setRestriction(int hallCode, int mode) {
    std::cout << "LegacyAccessSystem setRestriction : " << hallCode << " mode : " << mode;

    return 0;
}

int LegacyAccessSystem :: getStatus (int hallCode) {
    
    std::cout << "LegacyAccessSystem Get status: " << hallCode << "\n";
    return 0;
}

/*
#ifndef LEGACYACCESSSYSTEM_H
#define LEGACYACCESSSYSTEM_H

class LegacyAccessSystem{

    public: 
     int engageLock(int hallCode);

     int disengageLock(int hallCode);

     int setRestriction(int hallCode, int mode);

     int getStatus(int hallCode);
};
#endif
*/