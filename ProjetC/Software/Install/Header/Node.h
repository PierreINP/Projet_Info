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
	virtual void shapeStruct();	 // virtual
	virtual void createSons();	 // virtual
	virtual void cutStruct(Lexeme cutBegin, Lexeme cutEnd);//virtual
	bool isEntier(string a);
	bool isString(string a);
	bool isStd_Logic(string a); 

	
	string displayStruct() const;
	virtual string displaySonsAndAttributes() const;
	virtual string toString() const;

//accessors
	const string & getLabel()const;
	const list<Lexeme>::iterator & getLexIt()const;
	const vector<Node*> getSons()const;

	virtual const string & getLibraryID()const;
	virtual const string & getPackage()const;
	virtual const string & getEntityID()const;
	virtual const string & getName()const;
	virtual const string & getDirection()const;
	virtual const string & getType()const;
	virtual const string & getLowerBound()const;
	virtual const string & getUpperBound()const;
	virtual const string & getArchitectureID()const;
	virtual const string & getInitValue()const;

 
//Fonctions amies
	friend ostream& operator<<(ostream& out, const Node &n);
};

#endif 
