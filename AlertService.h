#ifndef ALERT_SERVICE_H
#define ALERT_SERVICE_H

#include <string>
#include "IncidentObserver.h"

// Concrete Observer 2

class AlertService : public IncidentObserver {
public:
    virtual ~AlertService() = default;

    // Observer stuff
    void update(const std::string& incidentId, const std::string& newStatus) override;

    // facade
    virtual void broadcastAlert(const std::string& message);
};

#endif