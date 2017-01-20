#include "./../Header/Node_entity.h"
#include <iostream> 


//builders
Node_entity::Node_entity(){
	label = "Entity"
}

Node_entity::~Node_entity(){}

//methods
bool Node_entity::checkStruct(){}

//accessors
string Node_entity::getEntityID{
	return e_ID;
}

