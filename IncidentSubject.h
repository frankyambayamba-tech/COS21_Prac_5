#ifndef INCIDENT_SUBJECT_H
#define INCIDENT_SUBJECT_H

#include <vector>
#include "IncidentObserver.h"

// The Subject base class
class IncidentSubject {
private:
    std::vector<IncidentObserver*> observers;

public:
    virtual ~IncidentSubject() = default;

    virtual void attach(IncidentObserver* observer);
    virtual void detach(IncidentObserver* observer);
    virtual void notifyObservers(const std::string& incidentId, const std::string& newStatus);
};

#endif 