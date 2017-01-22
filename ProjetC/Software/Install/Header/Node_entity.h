#ifndef _NODE_ENTITY_H_
#define _NODE_ENTITY_H_

#include "Node.h"

using namespace std;

class Node_entity : public Node {
private:
	string entity_ID;
public:
	Node_entity(list<Lexeme> parsing, list<Lexeme>::iterator it);
	~Node_entity();

//methods
	void createSons();
	void createStruct(list<Lexeme> parsing);
	bool checkStruct();

//accessors
	const string & getEntityID()const;
};

#endif 
