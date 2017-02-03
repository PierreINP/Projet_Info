#include "./../Header/Node_process.h"


//builders
	Node_process::Node_process(list<Lexeme>::iterator it):Node("Process",it){
		//cout << "--- Begin of creation : " << getLabel()<< endl;
		createStruct();
		checkStruct();
		//cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_process::~Node_process(){}

//methods
	void Node_process::createSons(){
	}

	void Node_process::createStruct(){
		list<Lexeme>::iterator it;

		structure.push_back(Lexeme("process"));
		for (it = ++lex_it; (*it).getName() != "process" ; it++){
			structure.push_back((*it).getName());
		}
		structure.push_back(Lexeme("process"));
		structure.push_back(Lexeme(";"));
	}

	bool Node_process::checkStruct(){

	}
	
	string Node_process::toString() const {
		stringstream flow;
		flow << "";
		return flow.str();
	}


