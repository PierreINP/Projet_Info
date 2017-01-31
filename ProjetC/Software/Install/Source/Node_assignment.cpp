#include "./../Header/Node_assignment.h"


//builders
	Node_assignment::Node_assignment(list<Lexeme>::iterator it):Node("Assignement",it){
		cout << "--- Begin of creation : " << getLabel()<< endl;
		createStruct();
		checkStruct();
		cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_assignment::~Node_assignment(){}

//methods
	void Node_assignment::createSons(){
	}

	void Node_assignment::createStruct(){
	}

	bool Node_assignment::checkStruct(){
	}



