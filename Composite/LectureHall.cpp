#include "LectureHall.h"
#include <iostream>

LectureHall :: LectureHall (int id, std::string name, CampusAccess * access) : CampusArea(name), id(id), access(access), secured(false) {}

LectureHall :: ~LectureHall () {}

void LectureHall :: lockDown () {

    std::cout << "LectureHall Locking down :"  << areaName << "\n";

    access -> lockArea (id);
}

void LectureHall :: unlock () {
    
    std::cout << "LectureHall Unlocking: " << areaName << "\n";

    access ->unlockArea (id);
}

void LectureHall :: evacuate () {
    
    std::cout << "LectureHall Evacuating: " << areaName << "\n";
}

bool LectureHall :: isSecured() const {

    return secured;
}

int LectureHall :: getId() const {
    
    return id;
}




/*
#ifndef LECUTUREHALL_H
#define LECTUREHALL_H

#include "CampusArea.h"
#include "CampusAccess.h"

class LectureHall : public CampusArea {

    public:

        LectureHall (int id, std::string name, CampusAccess * access);

        ~LectureHall () override;

        void lockDown () override;

        void unlock () override;

        void evacuate() override;

        int getId () const;

    private:

        int id;

        CampusAccess * access;
};
#endif*/