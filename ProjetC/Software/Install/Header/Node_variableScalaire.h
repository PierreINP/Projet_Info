#ifndef _NODE_VARIABLESCALAIRE_H_
#define _NODE_VARIABLESCALAIRE_H_

#include "Node.h"

using namespace std;

class Node_variableScalaire : public Node {
private:

public:
	Node_variableScalaire(list<Lexeme>::iterator it);
	~Node_variableScalaire();

//methods
	void createSons();
	void createStruct();
	bool checkStruct();
};

#endif 
