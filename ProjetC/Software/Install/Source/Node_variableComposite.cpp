#include "./../Header/Node_variableComposite.h"


//builders
	Node_variableComposite::Node_variableComposite(list<Lexeme>::iterator it):Node("VariableComposite",it){
		cout << "--- Begin of creation : " << getLabel()<< endl;
		createStruct();
		checkStruct();
		cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_variableComposite::~Node_variableComposite(){}

//methods
	void Node_variableComposite::createSons(){
	}

	void Node_variableComposite::createStruct(){
	}

	bool Node_variableComposite::checkStruct(){
	}



