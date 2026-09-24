#ifndef AUDIT_LOGGER_H
#define AUDIT_LOGGER_H

#include <string>
#include "IncidentObserver.h"

// Concrete Observer 3
class AuditLogger : public IncidentObserver {
public:
    virtual ~AuditLogger() = default;

    // Observer 
    void update(const std::string& incidentId, const std::string& newStatus) override;

    // Facade
    virtual void logIncident(const std::string& incidentId);
};

#endif 