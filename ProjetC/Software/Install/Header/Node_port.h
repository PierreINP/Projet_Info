#ifndef _NODE_PORT_H_
#define _NODE_PORT_H_

#include "Node.h"

using namespace std;

class Node_port : public Node {
private:
	list<Lexeme> name;
	Lexeme direction;
	Lexeme type;
public:
	Node_port(list<Lexeme>::iterator it);
	~Node_port();

//methods
	void createSons();
	void createSons(list<Lexeme> name, Lexeme direction, Lexeme type);
	void createStruct();
	bool checkStruct();

//accessors
	const string & getName()const;
	const string & getDirection()const;
	const string & getTypeD()const;

};

#endif 
