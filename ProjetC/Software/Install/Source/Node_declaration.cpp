#include "./../Header/Node_declaration.h"


//builders
	Node_declaration::Node_declaration(list<Lexeme>::iterator it):Node("Declaration",it){
		cout << "--- Begin of creation : " << getLabel()<< endl;
		createStruct();
		checkStruct();
		cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_declaration::~Node_declaration(){}

//methods
	void Node_declaration::createSons(){
	}

	void Node_declaration::createStruct(){
	}

	bool Node_declaration::checkStruct(){
	}



