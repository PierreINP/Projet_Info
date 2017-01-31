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
	vector <Node*> sons;
	
private:
	string label;
	
public:
	Node(string l, list<Lexeme>::iterator it);
	virtual ~Node();

//methods
	virtual void createStruct() = 0; // pure virtual
	virtual bool checkStruct() = 0;  // pure virtual
	void shapeStruct(Lexeme cutBegin, Lexeme cutEnd);
	bool isEntier(string a);
	string displaySons() const;
	string displayStruct() const;

//accessors
	const string & getLabel()const;
	const list<Lexeme>::iterator & getLexIt()const;
	const vector<Node*> getSons()const;

	virtual const string & getName()const;
	virtual const string & getDirection()const;
	virtual const string & getType()const;
	virtual const string & getLowerBound()const;
	virtual const string & getUpperBound()const;
 
//Fonctions amies
	friend ostream& operator<<(ostream& out, const Node &n);
};

#endif 
