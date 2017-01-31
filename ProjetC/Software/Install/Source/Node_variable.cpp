#include "./../Header/Node_variable.h"


//builders
	Node_variable::Node_variable(list<Lexeme>::iterator it):Node("Declaration",it){
		cout << "--- Begin of creation : " << getLabel()<< endl;
		createStruct();
		checkStruct();
		cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_variable::~Node_variable(){}

//methods
	void Node_variable::createSons(){
	}

	void Node_variable::createStruct(){
	}

	bool Node_variable::checkStruct(){
	}



