#ifndef SCENARIORUNNER_H
#define SCENARIORUNNER_H

class IncidentCoordinator;
class OperatorConsole;
class EmergencyWorkflowFacade;
class Incident;
class CampusComposite;
class LectureHall;
class CampusAccess;
class AlertService;
class AuditLogger;
class DashboardNotifier;
class SecurityTeam;
class MedicalTeam;
class FacilitiesTeam;
class LegacyAccessSystem;

// «client» — builds the object graph and drives both end-to-end scenarios.
class ScenarioRunner {
public:
    ScenarioRunner();
    ~ScenarioRunner();

    void runScenarioA();   // Fire in Lecture Hall A  facade workflow
    void runScenarioB();   // Second incident  manual commands + rejection + auto-dispatch

private:
    // Observer
    Incident*             incident1;
    Incident*             incident2;
    AlertService*         alert;
    AuditLogger*          logger;
    DashboardNotifier*    dashboard;

    // Adapter
    LegacyAccessSystem*   legacy;
    CampusAccess*         access;

    // Composite
    CampusComposite*      southCampus;
    LectureHall*          hallA;
    LectureHall*          hallB;

    // Mediator
    IncidentCoordinator*  coordinator;
    SecurityTeam*         security;
    MedicalTeam*          medical;
    FacilitiesTeam*       facilities;

    // Command
    OperatorConsole*      console;

    // Facade
    EmergencyWorkflowFacade* facade;
};

#endif