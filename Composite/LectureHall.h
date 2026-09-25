#ifndef LECTUREHALL_H
#define LECTUREHALL_H

#include "CampusArea.h"
#include "CampusAccess.h"
#include <string>

class LectureHall : public CampusArea {

    public:

        LectureHall (int id, std::string name, CampusAccess * access);   //Construct a hall (id, name and access adapter)

        ~LectureHall () override;

        void lockDown () override;

        void unlock () override;

        void evacuate() override;

        bool isSecured () const override;    //returns true if the hall is locked

        int getId () const;

    private:

        int id;

        CampusAccess * access;

        bool secured;
};
#endif