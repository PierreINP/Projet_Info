#ifndef _NODE_IFCONDITION_H_
#define _NODE_IFCONDITION_H_

#include "Node.h"

using namespace std;

class Node_ifCondition : public Node {
private:

public:
	Node_ifCondition(list<Lexeme>::iterator it);
	~Node_ifCondition();

//methods
	void createSons();
	void createStruct();
	bool checkStruct();
};

#endif 
