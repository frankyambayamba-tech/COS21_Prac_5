#ifndef AUDIT_LOGGER_H
#define AUDIT_LOGGER_H

#include <string>

// Concrete Observer (will inherit from an IncidentObserver interface later)
class AuditLogger {
public:
    virtual ~AuditLogger() = default;

    virtual void logIncident(const std::string& incidentId);
};

#endif // AUDIT_LOGGER_H