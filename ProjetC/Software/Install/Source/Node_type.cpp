#include "./../Header/Node_type.h"


//builders
	Node_type::Node_type(list<Lexeme>::iterator it):Node("Type",it){
		//cout << "--- Begin of creation : " << getLabel()<< endl;
		createStruct();
		checkStruct();
		//cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_type::~Node_type(){}

//methods
	void Node_type::createSons(){
	}

	void Node_type::createStruct(){
	}

	bool Node_type::checkStruct(){
	}



