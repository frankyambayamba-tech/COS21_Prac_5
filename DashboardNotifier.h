#ifndef DASHBOARD_NOTIFIER_H
#define DASHBOARD_NOTIFIER_H

#include "IncidentObserver.h"

// Concrete Observer 1
class DashboardNotifier : public IncidentObserver {
public:
    virtual ~DashboardNotifier() = default;

    // Updates the operator with the new status transition
    void update(const std::string& incidentId, const std::string& newStatus) override;
};

#endif