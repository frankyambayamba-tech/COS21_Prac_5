#include "Incident.h"

Incident::Incident(const std::string& id) : incidentId(id), status("Reported"){
    // Initially set to reported
}

void Incident::setStatus(const std::string& newStatus){
    status = newStatus;
    notifyObservers(incidentId, status);
}

std::string Incident::getStatus() const{
    return status;
}

std::string Incident::getId() const {
    return incidentId;
}