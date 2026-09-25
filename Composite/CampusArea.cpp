#include "CampusArea.h"

CampusArea :: CampusArea (std::string name) : areaName(name) {}

CampusArea :: ~CampusArea () {}

std::string CampusArea :: name () const {

    return areaName;
}