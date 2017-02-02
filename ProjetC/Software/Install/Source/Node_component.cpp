#include "./../Header/Node_component.h"


//builders
	Node_component::Node_component(list<Lexeme>::iterator it):Node("Component",it){
		//cout << "--- Begin of creation : " << getLabel()<< endl;
		createStruct();
		checkStruct();
		//cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_component::~Node_component(){}

//methods
	void Node_component::createSons(){
	}

	void Node_component::createStruct(){
	}

	bool Node_component::checkStruct(){
	}



