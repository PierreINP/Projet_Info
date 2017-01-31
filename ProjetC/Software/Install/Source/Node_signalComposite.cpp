#include "./../Header/Node_signalComposite.h"


//builders
	Node_signalComposite::Node_signalComposite(list<Lexeme>::iterator it):Node("SignalComposite",it){
		cout << "--- Begin of creation : " << getLabel()<< endl;
		createStruct();
		checkStruct();
		cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_signalComposite::~Node_signalComposite(){}

//methods
	void Node_signalComposite::createSons(){
	}

	void Node_signalComposite::createStruct(){
	}

	bool Node_signalComposite::checkStruct(){
	}



