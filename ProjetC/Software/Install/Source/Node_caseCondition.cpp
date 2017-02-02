#include "./../Header/Node_caseCondition.h"


//builders
	Node_caseCondition::Node_caseCondition(list<Lexeme>::iterator it):Node("CaseCondition",it){
		//cout << "--- Begin of creation : " << getLabel()<< endl;
		createStruct();
		checkStruct();
		//cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_caseCondition::~Node_caseCondition(){}

//methods
	void Node_caseCondition::createSons(){
	}

	void Node_caseCondition::createStruct(){
	}

	bool Node_caseCondition::checkStruct(){
	}



