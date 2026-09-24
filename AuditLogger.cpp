#include "AuditLogger.h"
#include <iostream>

void AuditLogger::update(const std::string& incidentId, const std::string& newStatus){
    std::cout << "[Audit Log] Auto-recorded status change: Incident " 
              << incidentId << " is now " << newStatus << std::endl;
}

void AuditLogger::logIncident(const std::string& incidentId) {
    // Steps commanded by facade
    std::cout << "[Audit Log] Workflow step initiated for Incident: " << incidentId << std::endl;
}