#ifndef _NODE_CASECONDITION_H_
#define _NODE_CASECONDITION_H_

#include "Node.h"

using namespace std;

class Node_caseCondition : public Node {
private:

public:
	Node_caseCondition(list<Lexeme>::iterator it);
	~Node_caseCondition();

//methods
	void createSons();
	void createStruct();
	bool checkStruct();
};

#endif 
