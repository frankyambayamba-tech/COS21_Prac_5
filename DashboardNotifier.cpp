#include "DashboardNotifier.h"
#include <iostream>

void DashboardNotifier::update(const std::string& incidentId, const std::string& newStatus) {
    // Updates live so operators can see the new status transition
    std::cout << "[Dashboard UI] Incident " << incidentId 
              << " status updated to: " << newStatus << std::endl;
}