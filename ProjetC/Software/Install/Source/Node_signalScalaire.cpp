#include "./../Header/Node_signalScalaire.h"


//builders
	Node_signalScalaire::Node_signalScalaire(list<Lexeme>::iterator it):Node("SignalScalaire",it){
		cout << "--- Begin of creation : " << getLabel()<< endl;
		createStruct();
		checkStruct();
		cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_signalScalaire::~Node_signalScalaire(){}

//methods
	void Node_signalScalaire::createSons(){
	}

	void Node_signalScalaire::createStruct(){
	}

	bool Node_signalScalaire::checkStruct(){
	}



