#ifndef _NODE_ENTITY_H_
#define _NODE_ENTITY_H_

#include "Node.h"

using namespace std;

class Node_entity : public Node {
private:
	string entity_ID;
public:
	Node_entity();
	~Node_entity();

//methods
	bool checkStruct();

//accessors
	const string & getEntityID()const;
};

#endif 
