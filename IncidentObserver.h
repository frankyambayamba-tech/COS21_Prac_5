#ifndef INCIDENT_OBSERVER_H
#define INCIDENT_OBSERVER_H

#include <string>

// The Observer interface
class IncidentObserver {
public:
    virtual ~IncidentObserver() = default;

    // Called by the subject when a state change occurs
    virtual void update(const std::string& incidentId, const std::string& newStatus) = 0;
};

#endif 