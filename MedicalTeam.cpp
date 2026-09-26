#include "MedicalTeam.h"


//Function 1:
MedicalTeam::MedicalTeam(){



}

//Function 2:
void MedicalTeam::onDispatch(CampusArea* location){

        std::cout << "Medical team treating injuries at " << location->name() << std::endl;
    }