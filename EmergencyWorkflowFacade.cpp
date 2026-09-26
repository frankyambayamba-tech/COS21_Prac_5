#include "EmergencyWorkflowFacade.h"
#include "IncidentCoordinator.h"
#include "CampusAccess.h"
#include "AlertService.h"
#include "AuditLogger.h"

EmergencyWorkflowFacade::EmergencyWorkflowFacade(IncidentCoordinator* coord,
                                                 CampusAccess* access,
                                                 AlertService* alert,
                                                 AuditLogger* log, ResponseComponent* secTeam, ResponseComponent* medTeam)
    : coordinator(coord), accessController(access), alertService(alert), logger(log), securityTeam(secTeam), medicalTeam(medTeam){}

EmergencyWorkflowFacade::~EmergencyWorkflowFacade(){
    // The client (ScenarioRunner or main) will manage the memory so facade does not delete objects
}

void EmergencyWorkflowFacade::handleMajorIncident(Incident* incident, CampusArea* area){
    // The facade does the subsystem calls in a sequence
    // 1. Log the incident
    logger->logIncident(incident->getId());

    //2. Change status to dispatched and dispatch the teams
    incident->setStatus("Dispatched");

    //3. Dispatch using mediator
    coordinator->handleDispatch(securityTeam, area);
    coordinator->handleDispatch(medicalTeam, area);

    // 4. Lock down the area
    area-> lockDown();

    //5. Broadcast the emergency alert
    alertService->broadcastAlert("Emergency in " + area->name());
}