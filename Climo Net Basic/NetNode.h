//This class will define the nodes in our neural network
#pragma once
#include <vector>
using namespace std;

class NetNode {
	vector<NetNode> inputNodes;
	vector<double> weights;
	double value, bias, error;

	void createWeights();	
	void determineValue();

public:
	NetNode(void);
	NetNode(vector<NetNode> &newInput);
	NetNode(vector<NetNode> &newInput, vector<double> newWeights);
	~NetNode(void);
	
	void setValue(double newValue);
	double getValue();
	double getError();
	double getWeight(int weightPos);
	vector<double> getWeights();
	void outBackProp(double targetVal, double learnRate);
	void hiddenBackProp(double learnRate, vector<NetNode> &connectedNodes, int nodePos);

};

