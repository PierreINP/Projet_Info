#include "./../Header/Node_port.h"

//builders
Node_port::Node_port(list<Lexeme>::iterator it):Node("Port",it){
	createStruct();
	cout << displayStruct() << endl;
	createSons();
	/*if(checkStruct() == true){
		cout << "	-> correct structure syntax"<< endl;
	}
	else {
		cout << "	-> incorrect structure syntax"<< endl;
	}*/
	cout << ">>> End of " << getLabel()<< " creation" << endl;
}
Node_port::~Node_port(){}

//methods
void Node_port::createSons(){}
void Node_port::createStruct(){
	list<Lexeme>::iterator it;
	
	for (it = lex_it; (*it).getName() != "end"; it++){
		structure.push_back((*it).getName());
	}
}

bool Node_port::checkStruct(){}

//accessors
const string & Node_port::getName()const{
	return name;
}

const string & Node_port::getDirection()const{
	return direction;
}

const string & Node_port::getTypeD()const{
	return type;
}


