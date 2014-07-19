#include "StdAfx.h"
#include "NetLayer.h"


NetLayer::NetLayer(void) {
	//the default constructor of the Network Layer class
}

NetLayer::NetLayer(int layerSize) {
	//the normal constructor for the base layer
	//this will construct the nodes needed based on the input size
	for (int i = 0; i < layerSize; i++) {
		NetNode *tempNode = new NetNode();
		NetLayer::layerNodes.push_back(*tempNode);
	}
}

NetLayer::NetLayer(vector<NetNode> &prevLayerNodes) {
	//create the nodes needed for a hidden or output layer
	for (int i = 0; i < prevLayerNodes.size(); i++) {
		NetNode *tempNode = new NetNode(prevLayerNodes);  //construct a new node with the previous layer's nodes
		NetLayer::layerNodes.push_back(*tempNode);  
	}
}

NetLayer::NetLayer(vector<NetNode> &prevLayerNodes, vector<double> newWeights) {
	//This constructor is for the reconstruction of an already established neural network
	for (int i = 0; i < prevLayerNodes.size(); i++) {
		NetNode *tempNode = new NetNode(prevLayerNodes, newWeights);  //construct a new node with the previous layer's nodes
		NetLayer::layerNodes.push_back(*tempNode);  
	}
}

NetLayer::~NetLayer(void) {
	//simple class destructor to lear out out vector
	NetLayer::layerNodes.clear();
}

void NetLayer::assignValues(vector<double> newValues) {
	//assign values for each of the nodes in the layer
	//should only be used for the input layer
	for (int i = 0; i < NetLayer::layerNodes.size(); i++) {
		NetLayer::layerNodes.at(i).setValue(newValues.at(i));
	}
}

void NetLayer::backProp(double learnRate, vector<NetNode> &connectedNodes) {
	//this is the method for the hidden layers
	for (int i = 0; i < NetLayer::layerNodes.size(); i++) {
		NetLayer::layerNodes.at(i).hiddenBackProp(learnRate, connectedNodes, i);
	}
}

void NetLayer::backProp(vector<double> targetVals, double learnRate) {
	//this is the method for the output layer
	for (int i = 0; i < NetLayer::layerNodes.size(); i++) {
		NetLayer::layerNodes.at(i).outBackProp(targetVals.at(i), learnRate);
	}
}

vector<vector<double>> NetLayer::getWeights() {
	//this function will grab all the weights for the child nodes
	vector<vector<double>> allWeights;
	for (int i = 0; i < NetLayer::layerNodes.size(); i++) {
		allWeights.push_back(NetLayer::layerNodes.at(i).getWeights());
	}
	return allWeights;
}

vector<NetNode> NetLayer::getNodes() {
	//simply return the current layer's nodes
	return NetLayer::layerNodes;
}