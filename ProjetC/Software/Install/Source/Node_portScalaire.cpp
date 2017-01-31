#include "./../Header/Node_portScalaire.h"

//builders
	Node_portScalaire::Node_portScalaire(list<Lexeme>::iterator it, string n, string d, string t):Node("PortScalaire",it),name(n),direction(d),type(t){
		cout << "--- Begin of creation : " << getLabel()<< endl;
		cout << "	Name : " << getName() << endl;
		cout << "	Direction : " << getDirection() << endl;
		cout << "	Type : " << getType() << endl;
		cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_portScalaire::~Node_portScalaire(){}

//methods
	void Node_portScalaire::createStruct(){}//Node virtual pure function not used for this class : subclass attributes are already set through constructor
	bool Node_portScalaire::checkStruct(){}//Node virtual pure function not used for this class : structure checking made at upper level of port

//accessors
	const string & Node_portScalaire::getName()const{
		return name;
	}

	const string & Node_portScalaire::getDirection()const{
		return direction;
	}

	const string & Node_portScalaire::getType()const{
		return type;
	}
