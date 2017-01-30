#include "./../Header/Node_portSignal.h"

//builders
	Node_portSignal::Node_portSignal(list<Lexeme>::iterator it, string n, string d, string t):Node("PortSignal",it),name(n),direction(d),type(t){//, int lB, int uB):Node("PortSignal",it),name(n),direction(d),type(t),lowerBound(lB),upperBound(uB){
		cout << "--- Begin of creation : " << getLabel()<< endl;
		cout << "	Name : " << getName() << endl;
		cout << "	Direction : " << getDirection() << endl;
		cout << "	Type : " << getType() << endl;
		cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_portSignal::~Node_portSignal(){}

//methods

	void Node_portSignal::createStruct(){}//Node virtual pure function not used for this class : subclass attributes are already set through constructor
	bool Node_portSignal::checkStruct(){}//Node virtual pure function not used for this class : structure checking made at upper level of port

//accessors
	const string & Node_portSignal::getName()const{
		return name;
	}

	const string & Node_portSignal::getDirection()const{
		return direction;
	}

	const string & Node_portSignal::getType()const{
		return type;
	}
	
	int Node_portSignal::getLowerBound(){
		return lowerBound;
	}

	int Node_portSignal::getUpperBound(){
		return upperBound;
	}

