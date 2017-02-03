#ifndef _NODE_ARCHITECTURE_H_
#define _NODE_ARCHITECTURE_H_

#include "Node.h"

using namespace std;

class Node_architecture : public Node {
private:
	string entity_ID;
	string architecture_ID;
	list<Lexeme>::iterator end_it;
public:
	Node_architecture(list<Lexeme>::iterator it, list<Lexeme>::iterator itEnd);
	~Node_architecture();

//methods
	void createSons();
	void createStruct();
	void shapeStruct();
	bool checkStruct();
	string displaySonsAndAttributes() const ;

//accessors
	const string & getEntityID()const;
	const string & getArchitectureID()const;
};

#endif 
