#include "IncidentCoordinator.h"



//Function 1:
void IncidentCoordinator::notify(ResponseComponent* colleague){

    if (SecurityTeam* sec = dynamic_cast<SecurityTeam*>(colleague)) 
    {
    // only runs if colleague really is a SecurityTeam
    // sec now safely points to it, with SecurityTeam's full interface available
        if (sec->hasInjuries())
        {
            for (ResponseComponent* c : responseList)
            {
                if (MedicalTeam* med = dynamic_cast<MedicalTeam*>(c))
                {
                    if (med->isAvailable())
                    {
                        handleDispatch(med, sec->getLastLocation());
                        break;   // one available team is enough, stop looking
                    }
                }
            }
        }
    }

    if (FacilitiesTeam* fac = dynamic_cast<FacilitiesTeam*>(colleague)) {
        if (fac->isAreaSecured()) {
            std::cout << "Area secured — holding other units back." << std::endl;
        }
    }
}


//Function 2:
void IncidentCoordinator::registerComponent(ResponseComponent* component){

    if(!component){

        return;
    }

    responseList.push_back(component);

    component->setMediator(this);

}

//Function 3:
bool IncidentCoordinator::handleDispatch(ResponseComponent* team, CampusArea* location){

    if(!team || !team->isAvailable()){

        return false;
    }

    team->setAvailability(false);

    //Ask about the name of the location
    team->onDispatch(location);

    return true;



}

//Function 4:
bool IncidentCoordinator::handleAlert(const string& message){

    if(message.empty()){

        return false;
    }

    cout << "Alert: " << message << endl;

    return true;

}