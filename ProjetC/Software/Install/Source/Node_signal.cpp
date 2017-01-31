#include "./../Header/Node_signal.h"

//builders
	Node_signal::Node_signal(list<Lexeme>::iterator it):Node("Signal",it){
		cout << "--- Begin of creation : " << getLabel()<< endl;
		createStruct();
		checkStruct();
		cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_signal::~Node_signal(){}

//methods
	void Node_signal::createSons(){
	}

	void Node_signal::createStruct(){
	}

	bool Node_signal::checkStruct(){
	}



