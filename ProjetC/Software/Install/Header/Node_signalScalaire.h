#ifndef _NODE_SIGNALSCALAIRE_H_
#define _NODE_SIGNALSCALAIRE_H_

#include "Node.h"

using namespace std;

class Node_signalScalaire : public Node {
private:

public:
	Node_signalScalaire(list<Lexeme>::iterator it);
	~Node_signalScalaire();

//methods
	void createSons();
	void createStruct();
	bool checkStruct();
};

#endif 
