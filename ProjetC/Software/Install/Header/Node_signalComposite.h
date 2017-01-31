#ifndef _NODE_SIGNALCOMPOSITE_H_
#define _NODE_SIGNALCOMPOSITE_H_

#include "Node.h"

using namespace std;

class Node_signalComposite : public Node {
private:

public:
	Node_signalComposite(list<Lexeme>::iterator it);
	~Node_signalComposite();

//methods
	void createSons();
	void createStruct();
	bool checkStruct();
};

#endif 
