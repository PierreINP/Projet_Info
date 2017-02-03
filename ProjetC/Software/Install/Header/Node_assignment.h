#ifndef _NODE_ASSIGNMENT_H_
#define _NODE_ASSIGNMENT_H_

#include "Node.h"

using namespace std;

class Node_assignment : public Node {
private:

public:
	Node_assignment(list<Lexeme>::iterator it);
	~Node_assignment();

//methods
	void createSons();
	void createStruct();
	bool checkStruct();
	string toString() const;
};

#endif 
