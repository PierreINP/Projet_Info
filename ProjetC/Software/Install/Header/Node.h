#ifndef NODE_H
#define NODE_H

#include "./../Header/Lexeme.h"

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>

using namespace std;

class Node {

protected:
	list<Lexeme> structure;
	list<Lexeme>::iterator lex_it;
	vector <Node*> enfants;
	
private:
	string label;
	
public:
	Node(string l, list<Lexeme>::iterator it);
	virtual ~Node();

//methods
	virtual void createSons() = 0;   // pure virtual
	virtual void createStruct(list<Lexeme> parsing) = 0; // pure virtual
	virtual bool checkStruct() = 0;  // pure virtual
	string displaySons() const;
	string displayStruct() const;

//accessors
	const string & getLabel()const;
	const list<Lexeme>::iterator & getLexIt()const;
	//const list<Lexeme> & getStructure()const;

//Fonctions amies
	friend ostream& operator<<(ostream& out, const Node &n);
};

#endif 
