#include "./../Header/Node_libraryUse.h"

//builders
	Node_libraryUse::Node_libraryUse(list<Lexeme>::iterator it):Node("LibraryUse",it){
		cout << "--- Begin of creation : " << getLabel()<< endl;
		createStruct();
		createSons();
		//shapeStruct();
		//checkStruct();
		cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_libraryUse::~Node_libraryUse(){}

//methods
	void Node_libraryUse::createSons(){}
	void Node_libraryUse::createStruct(){
		list<Lexeme>::iterator it;

		for (it = lex_it; (*it).getName() != ";" ; it++){//and (*it).getName() != "entity"
			structure.push_back((*it).getName());
		}
		structure.push_back(Lexeme(";"));
	}

	bool Node_libraryUse::checkStruct(){}

//accessors
	const string & Node_libraryUse::getLibraryID()const{
		return library_ID;
	}

	const string & Node_libraryUse::getPackage()const{
		return package;
	}


