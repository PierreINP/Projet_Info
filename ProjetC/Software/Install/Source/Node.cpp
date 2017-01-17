#include "./../Header/Node.h"
#include <iostream> 


//builders
Node::Node(string n_label){
	label = n_label;
}
Node::~Node() {}

//methods
Node* Node::createSon(Lexeme lex){
	Node son(lex.getType());
	return &son;
}

void Node::addSon(Node* enfant){enfants.push_back(enfant);}

void Node::getSons(){

	vector<Node*>::iterator it;
	for (it = enfants.begin(); it != enfants.end(); it++){
		cout << *it;
	}
}

//void Node::delSon(Node* enfant){
	//vector<Node*>::iterator it;
	//for (it = enfants.begin(); it != enfants.end(); it++){
	//	if (enfants[it] == enfant){
	//		enfants.pop_back(enfant);
	//	}
	//} 
	//if (enfants[enfant])
		//enfants.pop_back(enfant);
//}
/*
void accessSon(const Node* enfant){
}

Node* nextSon(){
}

Node* previousSon(){
}
*/
/*bool Node::hasNext(){
   if(parents != NULL)
	return true;
   else
	return false;
}*/

//accessors

//Node* Node::getNext(){return next;}

string Node::getLabel(){return label;}
list<Lexeme> Node::getStructure(){return structure;}



