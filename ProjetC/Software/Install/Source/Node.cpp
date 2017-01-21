#include "./../Header/Node.h"


//builders
Node::Node(string l): label(l){}
Node::~Node(){}

//accessors
const string & Node::getLabel()const{
	return label;
}

const list<Lexeme> & Node::getStructure()const{
	return structure;
}





