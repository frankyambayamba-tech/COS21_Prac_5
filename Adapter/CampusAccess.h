#ifndef CAMPUSACCESS_H
#define CAMPUSACCESS_H

class CampusAccess {

    public:

        virtual ~CampusAccess() {}          //Virtual Destructor 

        virtual bool lockArea(int id) = 0;    //lock area with the id

        virtual bool unlockArea(int id) = 0;  //unlock area with the id

        virtual bool restrictArea(int id, int level) = 0; //apply restriction level to the area
   
};
#endif