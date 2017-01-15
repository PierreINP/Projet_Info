#include "Node.h"
#include <iostream> 


//builders
Node::Node() {
	/*vector<Node*>::iterator it;
	for (it = parents.begin(); it != parents.end(); it++){
		it = NULL;
	} */
	value = 1;
}


//Node::Node(const Node& orig {next = orig.next;type = orig.type;// values assignaton

Node::~Node() {}

//methods

void addSon(){
   enfants.push_back()

}
/*bool Node::hasNext(){
   if(parents != NULL)
	return true;
   else
	return false;
}*/

//accessors
//Node* Node::getNext(){return next;}
int Node::getValue(){return value;}
//Lexeme* Node::getLexeme(){return type;}

//modifiers
/*void Node::setNext(Note* newNext){
   if(newNext == NULL)
	next = NULL;
   else
	next = newNext;//->next;
}*/

void Node::setValue(int val){
   value = val;
}

/*
void Node::setLexeme(int lexType){
   type = lexType;
}*/
