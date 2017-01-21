#include "./../Header/Node_root.h"
#include "./../Header/Node_library.h"
#include "./../Header/Node_entity.h"
#include "./../Header/Node_architecture.h"


//builders
Node_root::Node_root():Node("Root"){}
Node_root::~Node_root(){}

//methods
void Node_root::createSons(){
	enfants.push_back(new Node_library());
	enfants.push_back(new Node_entity());
	enfants.push_back(new Node_architecture());
}

bool Node_root::checkStruct(){}


