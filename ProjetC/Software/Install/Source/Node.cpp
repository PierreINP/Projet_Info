#include "./../Header/Node.h"
#include <iostream> 


//builders
Node::Node(string n_label){
	label = n_label;
}
Node::~Node() {}

//methods
Node Node::createSon(Lexeme lex){
	Node son(lex.getName());
	return son;
}

void Node::addSon(Node enfant){enfants.push_back(enfant);}

void Node::getSons(){
	vector<Node>::iterator it;
	cout << label << " node has following sons : " << endl; 
	for (it = enfants.begin(); it != enfants.end(); it++){
		cout << it->getLabel() << endl;
	}
}

string Node::getLabel(){return label;}
list<Lexeme> Node::getStructure(){return structure;}



