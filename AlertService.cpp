#include "AlertService.h"
#include <iostream>

void AlertService::update(const std::string& incidentId, const std::string& newStatus){
    if (newStatus == "Resolved"){
        broadcastAlert("Incident " + incidentId + " has been resolved.");
    }
}

void AlertService::broadcastAlert(const std::string& message){
    //These alerts are broadcasted only when told to by the faacde or an observer update
    std::cout << " BROADCAST: " << message << std::endl;
}