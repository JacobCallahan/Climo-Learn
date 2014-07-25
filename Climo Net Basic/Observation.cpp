#include "StdAfx.h"
#include "Observation.h"


Observation::Observation(void) {
	//default constructor just waits
}

Observation::Observation(std::string observationString) {
	//the recommended structure will validate the observation
	//then store it
	if (Observation::validateObservation(observationString)) {
		//if the observation is valid, then store it!
		Observation::storeObservation(observationString);
	}
}

Observation::~Observation(void) {
}

void Observation::storeObservation(std::string observationString) {
	//do stuff!
}

bool Observation::validateObservation(std::string observationString) {
	//do more stuff!
	return true;
}

void Observation::pullMonth_Day_Time() {
	//
	
}