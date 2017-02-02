#include "./../Header/Node_portComposite.h"

//builders
	Node_portComposite::Node_portComposite(list<Lexeme>::iterator it, string n, string d, string t, string lB, string uB):Node("PortComposite",it),name(n),direction(d),type(t),lowerBound(lB),upperBound(uB){
		//cout << "--- Begin of creation : " << getLabel()<< endl;
		cout << "	Name : " << getName() << endl;
		cout << "	Direction : " << getDirection() << endl;
		cout << "	Type : " << getType() << endl;
		cout << "	lowerBound : " << getLowerBound() << endl;
		cout << "	upperBound : " << getUpperBound() << endl;
		//cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_portComposite::~Node_portComposite(){}

//methods

	void Node_portComposite::createStruct(){}//Node virtual pure function not used for this class : subclass attributes are already set through constructor
	bool Node_portComposite::checkStruct(){}//Node virtual pure function not used for this class : structure checking made at upper level of port

//accessors
	const string & Node_portComposite::getName()const{
		return name;
	}

	const string & Node_portComposite::getDirection()const{
		return direction;
	}

	const string & Node_portComposite::getType()const{
		return type;
	}
	
	const string & Node_portComposite::getLowerBound()const{
		return lowerBound;
	}

	const string & Node_portComposite::getUpperBound()const{
		return upperBound;
	}

