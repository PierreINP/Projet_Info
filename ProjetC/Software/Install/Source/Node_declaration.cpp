#include "./../Header/Node_declaration.h"


//builders
	Node_declaration::Node_declaration(list<Lexeme>::iterator it):Node("Declaration",it){
		createStruct();
		checkStruct();	
	}

	Node_declaration::~Node_declaration(){}

//methods
	void Node_declaration::createSons(){
	}

	void Node_declaration::createStruct(){
		list<Lexeme>::iterator it;
	
		for (it = lex_it; (*it).getName() != "begin"; it++){
			structure.push_back((*it).getName());
		}
	}

	bool Node_declaration::checkStruct(){

	}



