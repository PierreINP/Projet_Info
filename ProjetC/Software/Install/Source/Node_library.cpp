#include "./../Header/Node_library.h"
#include "./../Header/Node_libraryUse.h"

//builders
	Node_library::Node_library(list<Lexeme>::iterator it):Node("Library",it){
		cout << "--- Begin of creation : " << getLabel()<< endl;
		createStruct();
		createSons();
		//shapeStruct();
		//checkStruct();
		cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_library::~Node_library(){}

//methods
	void Node_library::createSons(){} //No son
	void Node_library::createStruct(){
		list<Lexeme>::iterator it;

		for (it = lex_it; (*it).getName() != "use"; it++){
			structure.push_back((*it).getName());			
		}
	}

	bool Node_library::checkStruct(){}

//accessors
	const string & Node_library::getLibraryID()const{
		return library_ID;
	}


