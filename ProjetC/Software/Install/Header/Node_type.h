#ifndef _NODE_TYPE_H_
#define _NODE_TYPE_H_

#include "Node.h"

using namespace std;

class Node_type : public Node {
private:

public:
	Node_type(list<Lexeme>::iterator it);
	~Node_type();

//methods
	void createSons();
	void createStruct();
	bool checkStruct();
};

#endif 
