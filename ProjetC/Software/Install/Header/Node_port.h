#ifndef _NODE_PORT_H_
#define _NODE_PORT_H_

#include "Node.h"

using namespace std;

class Node_port : public Node {
private:
	list<string> names;
	string direction;
	string type;
	string lowerBound;
	string upperBound;
public:
	Node_port(list<Lexeme>::iterator it);
	~Node_port();

//methods
	void createScalaire(list<string> names, string direction, string type);
	void createComposite(list<string> names, string direction, string type, string lowerBound, string upperBound);
	void createStruct();
	bool checkStruct();
	string  displaySonsAndAttributes() const ;
};

#endif 
