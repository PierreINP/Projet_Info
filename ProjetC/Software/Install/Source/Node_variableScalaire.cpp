#include "./../Header/Node_variableScalaire.h"


//builders
	Node_variableScalaire::Node_variableScalaire(list<Lexeme>::iterator it):Node("VariableScalaire",it){
		cout << "--- Begin of creation : " << getLabel()<< endl;
		createStruct();
		checkStruct();
		cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_variableScalaire::~Node_variableScalaire(){}

//methods
	void Node_variableScalaire::createSons(){
	}

	void Node_variableScalaire::createStruct(){
	}

	bool Node_variableScalaire::checkStruct(){
	}



