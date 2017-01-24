#include "./../Header/Node_libraryUse.h"

//builders
Node_libraryUse::Node_libraryUse(list<Lexeme>::iterator it):Node("LibraryUse",it){}
Node_libraryUse::~Node_libraryUse(){}

//methods
void Node_libraryUse::createSons(){}
void Node_libraryUse::createStruct(){}
bool Node_libraryUse::checkStruct(){}

//accessors
const string & Node_libraryUse::getLibraryID()const{
	return library_ID;
}

const string & Node_libraryUse::getPackage()const{
	return package;
}


