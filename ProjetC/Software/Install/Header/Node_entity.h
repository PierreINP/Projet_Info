#ifndef _NODE_ENTITY_H_
#define _NODE_ENTITY_H_

#include "Node.h"

using namespace std;

class Node_entity : public Node {
private:
	string entity_ID;
	list<Lexeme>::iterator end_it;
public:
	Node_entity(list<Lexeme>::iterator it, list<Lexeme>::iterator itEnd);
	~Node_entity();

//methods
	void createSons();
	void createStruct();
	void shapeStruct();
	bool checkStruct();
	string displaySonsAndAttributes() const ;

//accessors
	const string & getEntityID()const;
};

#endif 
