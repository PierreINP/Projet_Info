#ifndef _NODE_DECLARATION_H_
#define _NODE_DECLARATION_H_

#include "Node.h"

using namespace std;

class Node_declaration : public Node {
private:

public:
	Node_declaration(list<Lexeme>::iterator it);
	~Node_declaration();

//methods
	void createSons();
	void createStruct();
	void shapeStruct();
	bool checkStruct();
	string  displaySonsAndAttributes() const ;
};

#endif 
