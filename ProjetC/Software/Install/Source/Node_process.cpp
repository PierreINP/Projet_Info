#include "./../Header/Node_process.h"


//builders
	Node_process::Node_process(list<Lexeme>::iterator it):Node("Process",it){
		cout << "--- Begin of creation : " << getLabel()<< endl;
		createStruct();
		checkStruct();
		cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_process::~Node_process(){}

//methods
	void Node_process::createSons(){
	}

	void Node_process::createStruct(){
	}

	bool Node_process::checkStruct(){
	}



