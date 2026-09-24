#ifndef ALERT_SERVICE_H
#define ALERT_SERVICE_H

#include <string>

// Concrete Observer (will inherit from an IncidentObserver interface later)
class AlertService {
public:
    virtual ~AlertService() = default;

    virtual void broadcastAlert(const std::string& message);
};

#endif // ALERT_SERVICE_H