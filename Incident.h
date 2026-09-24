#ifndef INCIDENT_H
#define INCIDENT_H

#include <string>
#include "IncidentSubject.h"

// The Concrete Subject
class Incident : public IncidentSubject {
private:
    std::string incidentId;
    std::string status; // Reported, dispatched, resolved

public:
    Incident(const std::string& id);
    virtual ~Incident() = default;

    // Changes the state and triggers notifyObservers()
    void setStatus(const std::string& newStatus);
    std::string getStatus() const;
    std::string getId() const;
};

#endif // INCIDENT_H