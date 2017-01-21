#ifndef _NODE_ROOT_H_
#define _NODE_ROOT_H_

#include "Node.h"

using namespace std;

class Node_root : public Node {
private:
public:
	Node_root(list<Lexeme>::iterator it);
	~Node_root();

//methods
	void createSons();
	bool checkStruct();
};

#endif 
