#include "EmergencyWorkflowFacade.h"
#include "IncidentCoordinator.h"
#include "LegacyAccessAdapter.h"
#include "LegacyAccessSystem.h"
#include "AlertService.h"
#include "AuditLogger.h"
#include "DashboardNotifier.h"
#include "Incident.h"
#include "SecurityTeam.h"
#include "MedicalTeam.h"
#include "FacilitiesTeam.h"
#include "OperatorConsole.h"
#include "DispatchUnitCommand.h"
#include "SecureAreaCommand.h"
#include "IssueAlertCommand.h"
#include "LectureHall.h"
#include "CampusComposite.h"
#include <iostream>

int main() {
    std::cout << "=== Initializing Campus Guard System ===" << std::endl;

    // 1. Initialize Observer Pattern (Incident & Services)
    Incident* currentIncident = new Incident("INC-2026-001");
    AlertService* alertService = new AlertService();
    AuditLogger* auditLogger = new AuditLogger();
    DashboardNotifier* dashboardNotifier = new DashboardNotifier();

    currentIncident->attach(alertService);
    currentIncident->attach(auditLogger);
    currentIncident->attach(dashboardNotifier);

    // 2. Initialize Adapter Pattern (Hardware Access)
    LegacyAccessSystem* hardwareSystem = new LegacyAccessSystem();
    CampusAccess* accessController = new LegacyAccessAdapter(hardwareSystem);

    // 3. Initialize Composite Pattern (Campus Layout)
    CampusComposite* southCampus = new CampusComposite("South Campus");
    LectureHall* hallA = new LectureHall(101, "LectureHall-A", accessController);
    LectureHall* hallB = new LectureHall(102, "LectureHall-B", accessController);
    southCampus->add(hallA);
    southCampus->add(hallB);

    // 4. Initialize Mediator Pattern (Response Teams)
    IncidentCoordinator* coordinator = new IncidentCoordinator();
    SecurityTeam* security = new SecurityTeam();
    MedicalTeam* medical = new MedicalTeam();
    FacilitiesTeam* facilities = new FacilitiesTeam();
    
    coordinator->registerComponent(security);
    coordinator->registerComponent(medical);
    coordinator->registerComponent(facilities);

    // 5. Initialize Command Pattern (Operator Invoker)
    OperatorConsole* console = new OperatorConsole();

    // 6. Initialize Facade Pattern
    EmergencyWorkflowFacade* facade = new EmergencyWorkflowFacade(
        coordinator, 
        accessController, 
        alertService, 
        auditLogger,
        security,
        medical
    );

    std::cout << "\n=== Running Major Incident Workflow via Facade ===" << std::endl;
    // The Facade handles the coordinated workflow
    facade->handleMajorIncident(currentIncident, hallA);

    std::cout << "\n=== Running Manual Operator Commands ===" << std::endl;
    // Demonstrating the command pattern working alongside the rest of the system
    Command* dispatchCmd = new DispatchUnitCommand(coordinator, medical, hallB);
    Command* secureCmd = new SecureAreaCommand(hallB, facilities);
    

    if (!console->submit(dispatchCmd)) {
        delete dispatchCmd;
    }
    
    if (!console->submit(secureCmd)) {
        delete secureCmd;
    }

    std::cout << "\n=== System Cleanup ===" << std::endl;
    // Clean up pointers (Ownership handled in main)
    delete facade;
    delete console;
    delete facilities;
    delete medical;
    delete security;
    delete coordinator;
    delete southCampus; // Assumes Composite deletes its children
    delete accessController; // Adapter deletes adaptee
    delete dashboardNotifier;
    delete auditLogger;
    delete alertService;
    delete currentIncident;

    return 0;
}