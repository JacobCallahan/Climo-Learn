#pragma once
#include <vector>
#include "NetNode.h"

using namespace std;

class NetLayer {
	vector<NetNode> layerNodes;

public:
	NetLayer(void);
	NetLayer(int layerSize);
	NetLayer(vector<NetNode> &prevLayerNodes);
	NetLayer(vector<NetNode> &prevLayerNodes, vector<double> newWeights);
	~NetLayer(void);
	
	void assignValues(vector<double> newValues);
	void backProp(double learnRate, vector<NetNode> &connectedNodes);
	void backProp(vector<double> targetVals, double learnRate);
	vector<vector<double>> getWeights();
	vector<NetNode> getNodes();
};

