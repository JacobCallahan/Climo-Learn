#include "StdAfx.h"
#include "NeuralNet.h"


NeuralNet::NeuralNet(void) {
	//Blank constructor does nothing for now
	learnRate = 0.1;
}

NeuralNet::NeuralNet(vector<int> layerStruct) {
	//this constructor will create a neural network based on the
	//layer structure
	for (int i = 0; i < layerStruct.size(); i++) {
		NeuralNet.addLayer(layerStruct.at(i)); //add the new layer
	}
	learnRate = 0.1;
}

NeuralNet::~NeuralNet(void) {
	NeuralNet::layers.clear(); //clear out our layer vector
	learnRate = 0.1;
}

void NeuralNet::backPropagate(vector<double> targetVals) {
	//this method is what starts the back propagation process
	for (int i = NeuralNet::layers.size(); i > 0; i--) {
		//loop backwards through the layers to propagate our new values
		if (i == NeuralNet::layers.size()) {
			//output layer
			NeuralNet::layers.at(i).backProp(targetVals, learnRate);
		} else {
			//hidden layer
			NeuralNet::layers.at(i).backProp(learnRate, NeuralNet::layers.at(i+1).getNodes());
		}
	}
}

void NeuralNet::setInput(vector<double> inputVals) {
	//this method will assign the new values to the first layer
	if (NeuralNet::layers.size() > 0) {
		NeuralNet::layers.at(0).assignValues(inputVals);
	}
}

vector<double> NeuralNet::getOutput() {
	vector<double> outPut;
	if (NeuralNet::layers.size() > 0) {
		//get the nodes from the last layer
		vector<NetNode> layerNodes = NeuralNet::layers.back().getNodes();
		//iterate through each of them 
		for (int i = 0; i < layerNodes.size(); i++) {
			//and add the value to the output array
			outPut.push_back(layerNodes.at(i).getValue());
		}
	} else {
		//if the size is 0, return an output of 0.0
		outPut.push_back(0.0);
	}
	return outPut;
}

void NeuralNet::addLayer(int nodeCount) {
	//create a new layer and add it to the vector
	NetLayer *newLayer = new NetLayer(nodeCount);
	NeuralNet::layers.push_back(*newLayer);
}

vector<double> NeuralNet::getPrediction(vector<double> inputValues) {
	//first, assign the values
	NeuralNet::setInput(inputValues);
	//then get the output and return!
	return NeuralNet::getOutput();
}

void NeuralNet::train(vector<double> inputVals, vector<double> answerVals) {
	//first, we get the prediction, then back propagate the results
	vector<double> results = NeuralNet::getPrediction(inputVals);

	//loop through the results and answers to find the difference
	//and initiate the back propagation algorithm for the node
	vector<NetNode> outPutLayerNodes = NeuralNet::layers.back().getNodes();
	//run the back propagation algorithm to adjust our weights
	NeuralNet::backPropagate(answerVals);

}