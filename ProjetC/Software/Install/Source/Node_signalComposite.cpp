#include "./../Header/Node_signalComposite.h"

//builders
	Node_signalComposite::Node_signalComposite(list<Lexeme>::iterator it, string n, string iV, string t, string lB, string uB):Node("SignalComposite",it),name(n),initValue(iV),type(t),lowerBound(lB),upperBound(uB){
		//cout << "--- Begin of creation : " << getLabel()<< endl;
		cout << "	Name : " << getName() << endl;
		cout << "	InitValue : " << getInitValue() << endl;
		cout << "	Type : " << getType() << endl;
		cout << "	lowerBound : " << getLowerBound() << endl;
		cout << "	upperBound : " << getUpperBound() << endl;
		//cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_signalComposite::~Node_signalComposite(){}

//methods

	void Node_signalComposite::createStruct(){}//Node virtual pure function not used for this class : subclass attributes are already set through constructor
	bool Node_signalComposite::checkStruct(){}//Node virtual pure function not used for this class : structure checking made at upper level of port

//accessors
	const string & Node_signalComposite::getName()const{
		return name;
	}

	const string & Node_signalComposite::getInitValue()const{
		return initValue;
	}

	const string & Node_signalComposite::getType()const{
		return type;
	}
	
	const string & Node_signalComposite::getLowerBound()const{
		return lowerBound;
	}

	const string & Node_signalComposite::getUpperBound()const{
		return upperBound;
	}

