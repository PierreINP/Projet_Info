#ifndef _NODE_COMPONENT_H_
#define _NODE_COMPONENT_H_

#include "Node.h"

using namespace std;

class Node_component : public Node {
private:

public:
	Node_component(list<Lexeme>::iterator it);
	~Node_component();

//methods
	void createSons();
	void createStruct();
	bool checkStruct();
};

#endif 
