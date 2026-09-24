#ifndef CAMPUS_ACCESS_H
#define CAMPUS_ACCESS_H

#include <string>

class CampusAccess{
    public:
        virtual ~CampusAccess() = default;

        virtual void lockArea(const std::string& zone) = 0;
        virtual void unlockArea(const std::string zone) =0;
        virtual void restrictArea(const std::string& zone) = 0;

};

#endif