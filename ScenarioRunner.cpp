#include "ScenarioRunner.h"
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

ScenarioRunner::ScenarioRunner() {
    std::cout << "Initializing Campus Guard System\n";

    // 1. Observer
    incident1 = new Incident("INC-2026-001");
    incident2 = new Incident("INC-2026-002");
    alert     = new AlertService();
    logger    = new AuditLogger();
    dashboard = new DashboardNotifier();

    incident1->attach(alert);
    incident1->attach(logger);
    incident1->attach(dashboard);

    incident2->attach(alert);
    incident2->attach(logger);
    incident2->attach(dashboard);

    // 2. Adapter
    legacy = new LegacyAccessSystem();
    access = new LegacyAccessAdapter(legacy);

    // 3. Composite
    southCampus = new CampusComposite("South Campus");
    hallA       = new LectureHall(101, "LectureHall-A", access);
    hallB       = new LectureHall(102, "LectureHall-B", access);
    southCampus->add(hallA);
    southCampus->add(hallB);

    // 4. Mediator
    coordinator = new IncidentCoordinator();
    security    = new SecurityTeam();
    medical     = new MedicalTeam();
    facilities  = new FacilitiesTeam();

    coordinator->registerComponent(security);
    coordinator->registerComponent(medical);
    coordinator->registerComponent(facilities);

    // 5. Command
    console = new OperatorConsole();

    // 6. Facade
    facade = new EmergencyWorkflowFacade(coordinator, access, alert, logger, security, medical);
}

/////////////////
ScenarioRunner::~ScenarioRunner() {
    delete facade;
    delete console;
    delete facilities;
    delete medical;
    delete security;
    delete coordinator;
    delete southCampus;      // deletes hallA_ and hallB_
    delete access;           // deletes adapter + legacy_
    delete dashboard;
    delete logger;
    delete alert;
    delete incident2;
    delete incident1;
}

//SCENARIO ONE
void ScenarioRunner::runScenarioA() {
    std::cout << "\nSCENARIO A: Fire in Lecture Hall A\n";

    facade->handleMajorIncident(incident1, hallA);
}

// SCENARIO TWO 
void ScenarioRunner::runScenarioB() {
    std::cout << "\nSCENARIO B: Second Incident at Lecture Hall B\n";

    // Step 1: Try to dispatch Security (they are busy  rejection) ---
    std::cout << "\nOperator: Attempting to dispatch Security to Hall B...\n";
    Command* dispatchSecurity = new DispatchUnitCommand(coordinator, security, hallB);
    if (!console->submit(dispatchSecurity)) {
        std::cout << "System: Security dispatch rejected - team is busy.\n";
        delete dispatchSecurity;   // console did not take ownership
    }

    // --- Step 2: Dispatch Medical instead (they are free) ---
    std::cout << "\nOperator: Dispatching Medical to Hall B...\n";
    Command* dispatchMedical = new DispatchUnitCommand(coordinator, medical, hallB);
    if (!console->submit(dispatchMedical)) {
        delete dispatchMedical;
    }

    // --- Step 3: Secure Hall B (lock + report back to facilities) ---
    std::cout << "\nOperator: Securing Hall B...\n";
    Command* secureHallB = new SecureAreaCommand(hallB, facilities);
    if (!console->submit(secureHallB)) {
        delete secureHallB;
    }

    // --- Step 4: Security is now free; they report an injured person ---
    std::cout << "\nSystem: Security freed from Hall A.\n";

    std::cout << "\nSecurity: Reporting injured person near Hall B...\n";
    security->reportInjuries(true, hallB);
}