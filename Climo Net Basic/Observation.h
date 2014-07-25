#pragma once
class Observation {
	//METAR KFBG 202058Z AUTO 11005KT 10SM FEW044 31/21 A3003 RMK AO2 SLP170 T03140208 57019 $

	//declare all of our variables needed to store the main elements of the observation
	int month, day, time, wind_Dir, wind_Speed, wind_Gust, vis, wx, msc_Cover, msc_Height, temp, dewp, altimeter;
	std::string OBSERVATION_STRING;
	/*
		time: \b\d{6}Z\b
		Vis: \b(\w[0-9\s\/]*SM|\s\d{4}\s)\b
		temp/DPs: \bM?\d{2,3}\/M?\d{2,3}\b
		alstg: \bA\d{4}\b
		SLP: SLP\d{3}
	*/

public:
	Observation(void);
	Observation(std::string obervationString);
	~Observation(void);

	void storeObservation(std::string observationString);
	bool validateObservation(std::string observationString);
	//holy void functions, Batman!
	void pullMonth_Day_Time();
	void pullWind_Dir_Speed_Gust();
	void pullVis();
	void pullWx();
	void pullMsc_Cover_Height();
	void pullMsc_Height();
	void pullTemp_Dewp();
	void pullAltimeter();
};

