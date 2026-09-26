#include "CampusComposite.h"
#include <iostream>

CampusComposite :: CampusComposite (std::string name) : CampusArea (name) {}

CampusComposite :: ~CampusComposite () {

    for (int i = 0; i < (int)children.size(); ++i){
        
        delete children[i];
    }

    children.clear();
}

void CampusComposite :: lockDown () {
    
    std::cout << "Composite Locking Down: " << areaName << "\n";

    for (int i = 0; i < (int)children.size(); ++i){
        children[i]->lockDown();
    }
}

void CampusComposite :: unlock () {

    std::cout << "Composite Unlocking: " << areaName << "\n";

    for (int i = 0; i < (int)children.size(); ++i){
        children[i]->unlock();
    }
}

void CampusComposite :: evacuate() {

    std::cout << "Composite Evacuating: " << areaName << "\n";

    for (int i = 0; i < (int)children.size(); ++i){
        children[i]->evacuate();
    }
}

bool CampusComposite :: isSecured () const {

    if (children.empty()){

        return false;
    }

    for (int i = 0; i < (int)children.size(); ++i){

        if (!children[i] -> isSecured()) {

            return false;
        }
    }
    
    return true;
}

void CampusComposite :: add(CampusArea * child) {
    children.push_back(child);
}

void CampusComposite :: remove(CampusArea * child) {
    
    for (int i = 0; i < (int)children.size(); ++i) {

        if(children[i] == child){{

            children.erase(children.begin() + i);

            delete child;

            return;
        }}
    }
    std::cerr << "Composite remove (): child not found\n";
}

std::vector<CampusArea *> CampusComposite :: getChildren() const {

    return children;
}

/*
#ifndef CAMPUSCOMPOSITE_H
#define CAMPUSCOMPOSITE_H

#include "CampusArea.h"
#include <vector>

class CampusComposite : public CampusArea {

    public:

        explicit CampusComposite (std::string name);

        ~CampusComposite () override;

        void lockDown () override;

        void unlock () override;

        void evacuate () override;

        void add (CampusArea * child) override;

        void remove (CampusArea * child) override;

        std::vector<CampusArea *> getChildren () const override;

    private:

        std::vector<CampusArea *> children;
};
#endif*/