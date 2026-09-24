#ifndef LEGACYACCESSSYSTEM_H
#define LEGACYACCESSSYSTEM_H

class LegacyAccessSystem{

    public: 
     int engageLock(int hallCode);        //Lock a hall by a code

     int disengageLock(int hallCode);     //Unlock a hall by a code

     int setRestriction(int hallCode, int mode);  //restrict a hall by a code and mode

     int getStatus(int hallCode);   //get a lock state of a particular hall
};
#endif