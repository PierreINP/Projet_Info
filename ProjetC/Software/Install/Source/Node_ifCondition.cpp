#include "./../Header/Node_ifCondition.h"


//builders
	Node_ifCondition::Node_ifCondition(list<Lexeme>::iterator it):Node("IfCondition",it){
		//cout << "--- Begin of creation : " << getLabel()<< endl;
		createStruct();
		checkStruct();
		//cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_ifCondition::~Node_ifCondition(){}

//methods
	void Node_ifCondition::createSons(){
	}

	void Node_ifCondition::createStruct(){
	}

	bool Node_ifCondition::checkStruct(){
	}



