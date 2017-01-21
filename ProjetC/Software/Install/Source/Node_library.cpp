#include "./../Header/Node_library.h"

//builders
Node_library::Node_library():Node("Library"){}
Node_library::~Node_library(){}

//methods
void Node_library::createSons(){}
bool Node_library::checkStruct(){}

//accessors
const string & Node_library::getLibraryID()const{
	return library_ID;
}


