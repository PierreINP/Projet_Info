#ifndef _NODE_PORT_H_
#define _NODE_PORT_H_

#include "Node.h"

using namespace std;

class Node_port : public Node {
private:
	string name;
	string direction;
	string type;
public:
	Node_port(list<Lexeme> parsing, list<Lexeme>::iterator it);
	~Node_port();

//methods
	void createSons();
	void createStruct(list<Lexeme> parsing);
	bool checkStruct();

//accessors
	const string & getName()const;
	const string & getDirection()const;
	const string & getTypeD()const;

};

#endif 
