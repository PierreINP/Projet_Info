#include "./../Header/Node_variableComposite.h"

//builders
	Node_variableComposite::Node_variableComposite(list<Lexeme>::iterator it, string n, string iV, string t, string lB, string uB):Node("VariableComposite",it),name(n),initValue(iV),type(t),lowerBound(lB),upperBound(uB){
		//cout << "--- Begin of creation : " << getLabel()<< endl;
		//cout << "	Name : " << getName() << endl;
		//cout << "	InitValue : " << getInitValue() << endl;
		//cout << "	Type : " << getType() << endl;
		//cout << "	lowerBound : " << getLowerBound() << endl;
		//cout << "	upperBound : " << getUpperBound() << endl;
		//cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_variableComposite::~Node_variableComposite(){}

//methods

	void Node_variableComposite::createStruct(){}//Node virtual pure function not used for this class : subclass attributes are already set through constructor
	bool Node_variableComposite::checkStruct(){}//Node virtual pure function not used for this class : structure checking made at upper level of port

	string Node_variableComposite::toString() const {
		stringstream flow;
		flow << "";
		return flow.str();
	}

//accessors
	const string & Node_variableComposite::getName()const{
		return name;
	}

	const string & Node_variableComposite::getInitValue()const{
		return initValue;
	}

	const string & Node_variableComposite::getType()const{
		return type;
	}
	
	const string & Node_variableComposite::getLowerBound()const{
		return lowerBound;
	}

	const string & Node_variableComposite::getUpperBound()const{
		return upperBound;
	}

