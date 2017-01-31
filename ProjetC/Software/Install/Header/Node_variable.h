#ifndef _NODE_VARIABLE_H_
#define _NODE_VARIABLE_H_

#include "Node.h"

using namespace std;

class Node_variable : public Node {
private:

public:
	Node_variable(list<Lexeme>::iterator it);
	~Node_variable();

//methods
	void createSons();
	void createStruct();
	bool checkStruct();
};

#endif 
