#ifndef INCIDENT_COORDINATOR_H
#define INCIDENT_COORDINATOR_H

#include <string>

// Concrete Mediator (will inherit from an IncidentMediator interface later)
class IncidentCoordinator {
public:
    virtual ~IncidentCoordinator() = default;

    virtual void updateStatus(const std::string& incidentId, const std::string& status);
    virtual void dispatchSecurity(const std::string& areaId);
    virtual void dispatchMedical(const std::string& areaId);
    
    // Additional mediator coordination methods will go here
};

#endif // INCIDENT_COORDINATOR_H