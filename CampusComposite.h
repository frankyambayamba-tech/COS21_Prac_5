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

        bool isSecured() const override;    //true only if all children are secured

        void add (CampusArea * child) override;

        void remove (CampusArea * child) override;

        std::vector<CampusArea *> getChildren () const override;

    private:

        std::vector<CampusArea *> children;
};
#endif