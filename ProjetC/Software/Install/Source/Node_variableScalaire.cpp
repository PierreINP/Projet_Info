#include "./../Header/Node_variableScalaire.h"

//builders
	Node_variableScalaire::Node_variableScalaire(list<Lexeme>::iterator it, string n, string iV, string t):Node("VariableScalaire",it),name(n),initValue(iV),type(t){
		//cout << "--- Begin of creation : " << getLabel()<< endl;
		//cout << "	Name : " << getName() << endl;
		//cout << "	InitValue : " << getInitValue() << endl;
		//cout << "	Type : " << getType() << endl;
		//cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_variableScalaire::~Node_variableScalaire(){}

//methods
	void Node_variableScalaire::createStruct(){}//Node virtual pure function not used for this class : subclass attributes are already set through constructor
	bool Node_variableScalaire::checkStruct(){}//Node virtual pure function not used for this class : structure checking made at upper level of port

	string Node_variableScalaire::toString() const {
		stringstream flow;
		return flow.str();
	}
//accessors
	const string & Node_variableScalaire::getName()const{
		return name;
	}

	const string & Node_variableScalaire::getInitValue()const{
		return initValue;
	}

	const string & Node_variableScalaire::getType()const{
		return type;
	}
