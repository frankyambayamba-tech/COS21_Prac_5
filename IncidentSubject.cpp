#include "IncidentSubject.h"
#include <algorithm>

void IncidentSubject::attach(IncidentObserver* observer) {
    observers.push_back(observer);
}

void IncidentSubject::detach(IncidentObserver* observer){
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void IncidentSubject::notifyObservers(const std::string& incidentId, const std::string& newStatus){
    for(IncidentObserver* obs : observers){
        obs->update(incidentId, newStatus);
    }
}