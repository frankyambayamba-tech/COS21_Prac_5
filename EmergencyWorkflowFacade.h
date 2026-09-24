#ifndef EMERGENCY_WORKFLOW_FACADE_H
#define EMERGENCY_WORKFLOW_FACADE_H

#include <string>

class IncidentCoordinator;
class CampusAccess;
class AlertService;
class AuditLogger;

class EmergencyWorkflowFacade {
    private:
        IncidentCoordinator* coordinator;
        CampusAccess* accessController;
        AlertService* alertService;
        AuditLogger* logger;
    
    public:
        //constructor for the system dependencies
        EmergencyWorkflowFacade(IncidentCoordinator* coord, CampusAccess* access,
                                AlertService* alert, AuditLogger* log);
        
        virtual ~EmergencyWorkflowFacade();

        void handleMajorIncident(const std::string& incidentId, const std::string& areaId);
};

#endif