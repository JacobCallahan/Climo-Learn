#include "StdAfx.h"
#include "Observation.h"
#include <regex>

using namespace std;

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

/*
	time: \b\d{6}Z\b
	Vis: \b(\w[0-9\s\/]*SM|\s\d{4}\s)\b
	temp/DPs: \bM?\d{2,3}\/M?\d{2,3}\b
	alstg: \bA\d{4}\b
	SLP: SLP\d{3}
*/

void Observation::pullMonth_Day_Time() {
	//This function will pull the date and time from the ob
	//and store it in the appropriate variables

	regex_search("",Observation::elMatch);
	Observation::month = int("");
	Observation::day;
	Observation:time;
	
}