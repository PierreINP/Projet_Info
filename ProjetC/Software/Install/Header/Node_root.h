#ifndef _NODE_ROOT_H_
#define _NODE_ROOT_H_

#include "Node.h"

using namespace std;

class Node_root : public Node {
private:
public:
	Node_root(list<Lexeme> parsing,list<Lexeme>::iterator it);
	~Node_root();

//methods
	void createSons();
	void createStruct();//Node virtual pure function not used for this class : structure checking is made during parsing
	bool checkStruct(); //Node virtual pure function not used for this class : structure copied from VHDL source parsing
};

#endif 
