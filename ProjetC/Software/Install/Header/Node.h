#ifndef NODE_H
#define NODE_H

#include "./../Header/Lexeme.h"

#include <vector>
#include <list>
#include <string>

using namespace std;

class Node {
private:
	string label;
	list<Lexeme> structure;
	vector <Node*> enfants;
public:
	Node(string label);
	virtual ~Node();

//methods
	Node* createSon(Lexeme lex);
	void addSon(Node* enfant);
	void getSons();
	//void delSon(Node* enfant);
	//void accessSon(const Node* enfant);
	//Node* nextSon();
	//Node* previousSon();
	//virtual bool checkStruct() = 0; // pure virtual
//Remarque : renvoyer le numero de l'iterateur avec le fils courant

//accessors
	string getLabel();
	list<Lexeme> getStructure();
};

#endif 
