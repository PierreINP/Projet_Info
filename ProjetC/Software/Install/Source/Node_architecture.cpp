#include "./../Header/Node_architecture.h"

//builders
Node_architecture::Node_architecture():Node("Architecture"){}
Node_architecture::~Node_architecture(){}

//methods
void Node_architecture::createSons(){}
bool Node_architecture::checkStruct(){}

//accessors
const string & Node_architecture::getEntityID()const{
	return entity_ID;
}

const string & Node_architecture::getArchitectureID()const{
	return architecture_ID;
}



