#include "./../Header/Node.h"
#include <iostream> 


//builders
Node::Node(string l): label(l){}
Node::~Node(){}

//methods
/*
Node *Node::createSon(Lexeme special){
	if(special.getName() == "entity"){
		Node* son = new Node_entity();
	}
	else{
		cout << "error" << endl;
	}
	
	return son;
}

void Node::addSon(Node* enfant){enfants.push_back(enfant);}
void Node::addSon(){enfants.push_back(new Node());}

void Node::getSons(){
	vector<Node>::iterator it;
	cout << label << " node has following sons : " << endl; 
	for (it = enfants.begin(); it != enfants.end(); it++){
		cout << *it->getLabel() << endl;
	}
}

void Node::delSon(Node* enfant){
	vector<Node*>::iterator it;
	for (it = enfants.begin(); it != enfants.end(); it++){
		if (enfants[it] == enfant){
			enfants.pop_back(enfant);
		}
	} 
	if (enfants[enfant])
		enfants.pop_back(enfant);
}
*/


//accessors

const string & Node::getLabel()const{
	return label;
}

const list<Lexeme> & Node::getStructure()const{
	return structure;
}





