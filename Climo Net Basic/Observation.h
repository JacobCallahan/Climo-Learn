#pragma once
class Observation {
	//METAR KFBG 202058Z AUTO 11005KT 10SM FEW044 31/21 A3003 RMK AO2 SLP170 T03140208 57019 $

	//declare all of our variables needed to store the main elements of the observation
	int month, day, time, wind_Dir, wind_Speed, wind_Gust, vis, wx, msc_Cover, msc_Height, temp, dewp, altimeter;
	std::string OBSERVATION_STRING;
	//will use this for regex matching
	typedef match_results<const char*> elMatch;
	std::tr1::match_results<std::string::const_iterator> elResult;

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

