#include "ResponseComponent.h"
#include "IncidentMediator.h"

//Function 0:
ResponseComponent::ResponseComponent() : mediator(nullptr), available(true) {

}
//Function 1:
void ResponseComponent::setMediator(IncidentMediator* mediator){

    this->mediator = mediator;

}

//Function 2:
bool ResponseComponent::isAvailable() const{

    return available;

}

//Function 3:
void ResponseComponent::setAvailability(bool available){

    this->available = available;

}

//Function 4:
void ResponseComponent::changed(){

    mediator->notify(this);

}

//Funtion 5:
ResponseComponent::~ResponseComponent(){



}