#include "./../Header/Node.h"

//builders
Node::Node(string l, list<Lexeme>::iterator it): label(l), lex_it(it){}
Node::~Node(){}

//accessors
const string & Node::getLabel()const{
	return label;
}

const list<Lexeme> & Node::getStructure()const{
	return structure;
}

const list<Lexeme>::iterator & Node::getLexIt()const{
	return lex_it;
}

//methods
string  Node::displaySons() const {  
	vector<Node*>::const_iterator it;
	stringstream sons;

	sons << "Current node " << getLabel() << " has following sons : "<< endl; 
	for (it = enfants.begin(); it != enfants.end(); it++){
		sons << (*it)->getLabel() << endl;
	}
	return sons.str();
}

//friend function
 ostream& operator<<(ostream& out, const Node &n){
	out << n.displaySons()<< endl;
	return out;
}


