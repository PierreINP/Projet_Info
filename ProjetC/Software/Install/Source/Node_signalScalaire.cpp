#include "./../Header/Node_signalScalaire.h"

//builders
	Node_signalScalaire::Node_signalScalaire(list<Lexeme>::iterator it, string n, string iV, string t):Node("SignalScalaire",it),name(n),initValue(iV),type(t){
		//cout << "--- Begin of creation : " << getLabel()<< endl;
		cout << "	Name : " << getName() << endl;
		cout << "	InitValue : " << getInitValue() << endl;
		cout << "	Type : " << getType() << endl;
		//cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_signalScalaire::~Node_signalScalaire(){}

//methods
	void Node_signalScalaire::createStruct(){}//Node virtual pure function not used for this class : subclass attributes are already set through constructor
	bool Node_signalScalaire::checkStruct(){}//Node virtual pure function not used for this class : structure checking made at upper level of port

//accessors
	const string & Node_signalScalaire::getName()const{
		return name;
	}

	const string & Node_signalScalaire::getInitValue()const{
		return initValue;
	}

	const string & Node_signalScalaire::getType()const{
		return type;
	}
