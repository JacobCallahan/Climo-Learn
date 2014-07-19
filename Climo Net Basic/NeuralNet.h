#pragma once
#include "NetLayer.h"

class NeuralNet {

	vector<NetLayer> layers;
	double learnRate;

	void backPropagate(vector<double> targetVals);
	void setInput(vector<double> inputVals);
	vector<double> getOutput();

public:
	NeuralNet(void);
	NeuralNet(vector<int>layerStruct);
	~NeuralNet(void);

	void addLayer(int nodeCount);
	vector<double> getPrediction(vector<double> inputValues);
	void train(vector<double> inputVals, vector<double> answerVals);
};

