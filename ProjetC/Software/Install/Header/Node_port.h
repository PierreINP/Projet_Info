#ifndef _NODE_PORT_H_
#define _NODE_PORT_H_

#include "Node.h"

using namespace std;

class Node_port : public Node {
private:
	list<string> names;
	string direction;
	string type;
public:
	Node_port(list<Lexeme>::iterator it);
	~Node_port();

//methods
	void createSons(list<string> names, string direction, string type);//, int lowerBound=0, int upperBound=0);
	void createStruct();
	bool checkStruct();

//accessors
	const list<string> & getNames()const;
	const string & getDirection()const;
	const string & getTypeD()const;

};

#endif 
