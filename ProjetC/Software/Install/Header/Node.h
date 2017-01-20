#ifndef NODE_H
#define NODE_H

#include "./../Header/Lexeme.h"

#include <vector>
#include <list>
#include <string>

using namespace std;

class Node {
private:
	list<Lexeme> structure;
	vector <Node> enfants;
public:
	Node(string label);
	virtual ~Node();

//methods
	Node createSon(Lexeme lex);
	void addSon(Node enfant);
	void getSons();

//accessors
	string getLabel();
	list<Lexeme> getStructure();
};

#endif 
