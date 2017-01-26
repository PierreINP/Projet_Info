#include "./../Header/Node_architecture.h"

//builders
	Node_architecture::Node_architecture(list<Lexeme>::iterator it, list<Lexeme>::iterator itEnd):Node("Architecture",it), end_it(itEnd){
		cout << "--- Begin of creation : " << getLabel()<< endl;
		createStruct();
		createSons();
		//shapeStruct();
		//checkStruct();
		cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_architecture::~Node_architecture(){}

//methods
	void Node_architecture::createSons(){}
	void Node_architecture::createStruct(){
		list<Lexeme>::iterator it;
	
		for (it = lex_it; it != end_it; it++){
			structure.push_back((*it).getName());
		}
	}
	bool Node_architecture::checkStruct(){}

//accessors
	const string & Node_architecture::getEntityID()const{
		return entity_ID;
	}

	const string & Node_architecture::getArchitectureID()const{
		return architecture_ID;
	}



