#include "./../Header/Node_library.h"

//builders
Node_library::Node_library(list<Lexeme>::iterator it):Node("Library",it){
//	createSons()
	createStruct();
}
Node_library::~Node_library(){}

//methods
void Node_library::createSons(){}
void Node_library::createStruct(){
	list<Lexeme>::iterator it;

	for (it = lex_it; (*it).getName() != "entity"; it++){
		structure.push_back((*it).getName());
		if(((*it).getName() == "use") and ((*it).getType() == "keyword")){
			while(((*it).getName() != ";") or ((*it).getType() != "special")){
				it++;
			}
		}		
	}
	cout << displayStruct() << endl << endl ;
}

bool Node_library::checkStruct(){}

//accessors
const string & Node_library::getLibraryID()const{
	return library_ID;
}


