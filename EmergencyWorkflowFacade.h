#ifndef EMERGENCY_WORKFLOW_FACADE_H
#define EMERGENCY_WORKFLOW_FACADE_H

#include <string>

#include "IncidentCoordinator.h"
#include "CampusAccess.h"
#include "AlertService.h"
#include "AuditLogger.h"
#include "Incident.h"
#include "CampusArea.h"
#include "ResponseComponent.h"

class EmergencyWorkflowFacade {
    private:
        IncidentCoordinator* coordinator;
        CampusAccess* accessController;
        AlertService* alertService;
        AuditLogger* logger;
        ResponseComponent* securityTeam;
        ResponseComponent* medicalTeam;
    
    public:
        //constructor for the system dependencies
        EmergencyWorkflowFacade(IncidentCoordinator* coord, CampusAccess* access,
                                AlertService* alert, AuditLogger* log, ResponseComponent* secTeam, ResponseComponent* medTeam);
        
        virtual ~EmergencyWorkflowFacade();

        void handleMajorIncident(Incident* incident, CampusArea* area);
};

#endif