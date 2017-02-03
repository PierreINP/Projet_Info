#ifndef _NODE_PROCESS_H_
#define _NODE_PROCESS_H_

#include "Node.h"

using namespace std;

class Node_process : public Node {
private:

public:
	Node_process(list<Lexeme>::iterator it);
	~Node_process();

//methods
	void createSons();
	void createStruct();
	bool checkStruct();
	string toString() const; 
};

#endif 
