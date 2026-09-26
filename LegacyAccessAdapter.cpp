#include "LegacyAccessAdapter.h"
#include <iostream>

LegacyAccessAdapter :: LegacyAccessAdapter (LegacyAccessSystem * legacy) : adaptee (legacy) {}

LegacyAccessAdapter :: ~LegacyAccessAdapter () {
    delete adaptee;
    adaptee = nullptr;
}

int LegacyAccessAdapter :: mapId (int id) const {
    return 100 + id;
}

bool LegacyAccessAdapter :: lockArea (int id) {

    int code = mapId(id);

    int rc = adaptee -> engageLock(code);

    if (rc != 0){
        std :: cerr << "Adapter lockArea : " << id << "failed; code " << rc << "\n";
    }

    return true;
}

bool LegacyAccessAdapter :: unlockArea (int id) {

    return adaptee -> disengageLock(mapId(id)) == 0;
}

bool LegacyAccessAdapter :: restrictArea (int id, int level) {

    return adaptee -> setRestriction(mapId(id), level) == 0;
}