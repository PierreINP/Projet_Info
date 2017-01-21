#ifndef NODE_H
#define NODE_H

#include "./../Header/Lexeme.h"

#include <iostream>
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
	Node(string l);
	virtual ~Node();

//methods
	//Node* createSon(Lexeme special);
	//void addSon(Node* enfant);
	//void addSon();
	//void delSon(Node* enfant);
	//void getSons();
	virtual void createSons() = 0;  // pure virtual
	virtual bool checkStruct() = 0; // pure virtual


//accessors
	const string & getLabel()const;
	const list<Lexeme> & getStructure() const;
};

#endif 
