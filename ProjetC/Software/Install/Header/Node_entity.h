#ifndef _NODE_ENTITY_H_
#define _NODE_ENTITY_H_

#include "./../Header/Node.h"

using namespace std;

class Node_entity : public virtual Node {
private:
	string entity_ID;
public:
	Node_entity();
	virtual ~Node_entity();

//methods
	virtual bool checkStruct();

//accessors
	string getEntityID();
};

#endif 
