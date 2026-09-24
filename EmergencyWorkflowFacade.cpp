#include "EmergencyWorkflowFacade.h"
#include "IncidentCoordinator.h"
#include "CampusAccess.h"
#include "AlertService.h"
#include "AuditLogger.h"

EmergencyWorkflowFacade::EmergencyWorkflowFacade(IncidentCoordinator* coord,
                                                 CampusAccess* access,
                                                 AlertService* alert,
                                                 AuditLogger* log)
    : coordinator(coord), accessController(access), alertService(alert), logger(log){}

EmergencyWorkflowFacade::~EmergencyWorkflowFacade(){
    // The client (ScenarioRunner or main) will manage the memory so facade does not delete objects
}

void EmergencyWorkflowFacade::handleMajorIncident(const std::string& incidentId, const std::string& areaId){
    // The facade does the subsystem calls in a sequence
    // 1. Log the incident
    logger->logIncident(incidentId);

    //2. Change status to dispatched and dispatch the teams
    coordinator->updateStatus(incidentId, "Dispatched");
    coordinator->dispatchSecurity(areaId);
    coordinator->dispatchMedical(areaId);

    //3. Restrict access annd lock down the area
    accessController->lockArea(areaId);

    //4. Broadcast the emergency alert
    alertService->broadcastAlert("Emergency in " + areaId);
}