#ifndef _NODE_VARIABLECOMPOSITE_H_
#define _NODE_VARIABLECOMPOSITE_H_

#include "Node.h"

using namespace std;

class Node_variableComposite : public Node {
private:

public:
	Node_variableComposite(list<Lexeme>::iterator it);
	~Node_variableComposite();

//methods
	void createSons();
	void createStruct();
	bool checkStruct();
};

#endif 
