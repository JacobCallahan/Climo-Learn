#include "StdAfx.h"
#include "NetNode.h"

NetNode::NetNode(void) {
	//default constructor will be for the base layer
	value = 0, bias = 0;
}

NetNode::NetNode(vector<NetNode> &newInput) {
	//assign the new input nodes to this node's input
	NetNode::inputNodes = newInput;
	NetNode::createWeights();
}

NetNode::NetNode(vector<NetNode> &newInput, vector<double> newWeights) {
	//this constructor is mainly for reestablishing a saved neural network
	NetNode::inputNodes = newInput;
	NetNode::weights = newWeights;
}

NetNode::~NetNode(void) {
	//destructor
	NetNode::inputNodes.clear();
	NetNode::weights.clear();
}

void NetNode::createWeights() {
	//loop through each input node and assign a random weight to each
	for(int input = 0; input < NetNode::inputNodes.size(); input++) {
		NetNode::weights.push_back(rand());
	}
}

void NetNode::determineValue() {
	//loop through all the inputs and weights linked to the node
	int i = 0;
	double sum = 0;
	for (int input = 0; input < NetNode::inputNodes.size(); input++) {
		sum += NetNode::inputNodes.at(input).getValue() * NetNode::weights.at(i);
	}
	//assign the new sum to the node's value
	sum += NetNode::bias; //add in the bias
	sum = 1 / (1 + exp(-sum)); //apply a sigmoid function
	NetNode::value = sum;
}

void NetNode::setValue(double newValue) {
	//set the current node value equal to the new value
	//should only be used on the base layer
	NetNode::value = newValue;
}

double NetNode::getValue() {
	//simply calculate and return the current value
	NetNode::determineValue();
	return NetNode::value;
}

vector<double> NetNode::getWeights() {
	//return the current weight vector
	return NetNode::weights;
}

double NetNode::getError() {
	//return the current error
	return NetNode::error;
}

void NetNode::outBackProp(double targetVal, double learnRate) {
	//this function will determine the error and adjust the weights
	double error, weightChange, sum = 0;
	for (int input = 0; input < NetNode::inputNodes.size(); input++) {
		sum += NetNode::inputNodes.at(input).getValue() * NetNode::weights.at(i);
	}
	//calculate the error
	NetNode::error = (NetNode::value - targetVal) * NetNode::value * (1 - NetNode::value);
	//determine the amount we want to adjust each weight by
	weightChange = -learnRate * NetNode::error * sum;
	for (int i = 0; i < NetNode::weights.size(); i++) {
		//apply the new change to all our weights
		NetNode::weights.at(i) = NetNode::weights.at(i) + weightChange;
	}
	//finally, we update our bias value
	NetNode::bias = NetNode::bias + learnRate * NetNode::error;
}

void NetNode::hiddenBackProp(double learnRate, vector<NetNode> &connectedNodes, int nodePos) {
	//this function will determine the error and adjust the weights
	double error, weightChange, sum = 0;
	for (int i = 0; i < NetNode::inputNodes.size(); i++) {
		//multiply the error of each connected node by the connecting weight
		sum += connectedNodes.at(i).getError() * connectedNodes.at(i).getWeight(nodePos);
	}
	//calculate the error
	error = NetNode::value * (1 - NetNode::value) * sum;

	//determine the amount we want to adjust each weight by
	weightChange = -learnRate * error * sum;
	for (int i = 0; i < NetNode::weights.size(); i++) {
		//apply the new change to all our weights
		NetNode::weights.at(i) = NetNode::weights.at(i) + weightChange;
	}
	//finally, we update our bias value
	NetNode::bias = NetNode::bias + learnRate * error;
}

