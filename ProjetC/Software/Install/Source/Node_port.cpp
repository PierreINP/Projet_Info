#include "./../Header/Node_port.h"

//builders
Node_port::Node_port(list<Lexeme>::iterator it):Node("Port",it){}
Node_port::~Node_port(){}

//methods
void Node_port::createSons(){}
void Node_port::createStruct(){}
bool Node_port::checkStruct(){}

//accessors
const string & Node_port::getName()const{
	return name;
}

const string & Node_port::getDirection()const{
	return direction;
}

const string & Node_port::getTypeD()const{
	return type;
}


