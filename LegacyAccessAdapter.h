#ifndef LEGACYACCESSADAPTER_H
#define LEGACYACCESSADAPTER_H

#include "CampusAccess.h"
#include "LegacyAccessSystem.h"

class LegacyAccessAdapter : public CampusAccess {

    public:

    explicit LegacyAccessAdapter (LegacyAccessSystem* legacy);

    ~LegacyAccessAdapter () override; //Deletes adaptee

    bool lockArea (int id) override; //CampusAccess Implementation

    bool unlockArea (int id) override;

    bool restrictArea (int id, int level) override;

    ///////////
    private:

    LegacyAccessSystem* adaptee;

    int mapId (int id) const; 

};
#endif