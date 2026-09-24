#ifndef CAMPUSAREA_H
#define CAMPUSAREA_H

#include <string>
#include <vector>

class CampusArea {

    public:

        explicit CampusArea (std::string name);  //construct an area with a name

        virtual ~CampusArea (); //virtual destructor

        virtual void lockDown () = 0;  //lock down an area (leaf/composite)

        virtual void unlock () = 0;    //unlock an area (leaf/composite)

        virtual void evacuate () = 0;   //evacuate an area 

        virtual bool isSecured () const = 0;

        virtual void add (CampusArea *) {}   

        virtual void remove (CampusArea *) {}

        virtual std::vector<CampusArea *> getChildren () const { return {}; }

        std::string name () const;     //return an areas name

    //////////
    protected:

        std::string areaName;   //an areas name
};
#endif