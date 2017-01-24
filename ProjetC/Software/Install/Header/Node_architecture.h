#ifndef _NODE_ARCHITECTURE_H_
#define _NODE_ARCHITECTURE_H_

#include "Node.h"

using namespace std;

class Node_architecture : public Node {
private:
	string entity_ID;
	string architecture_ID;
public:
	Node_architecture(list<Lexeme>::iterator it);
	~Node_architecture();

//methods
	void createSons();
	void createStruct();
	bool checkStruct();

//accessors
	const string & getEntityID()const;
	const string & getArchitectureID()const;
};

#endif 
