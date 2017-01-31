#ifndef _NODE_SIGNAL_H_
#define _NODE_SIGNAL_H_

#include "Node.h"

using namespace std;

class Node_signal : public Node {
private:

public:
	Node_signal(list<Lexeme>::iterator it);
	~Node_signal();

//methods
	void createSons();
	void createStruct();
	bool checkStruct();
};

#endif 
