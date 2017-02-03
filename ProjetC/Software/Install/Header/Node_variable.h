#ifndef _NODE_VARIABLE_H_
#define _NODE_VARIABLE_H_

#include "Node.h"

using namespace std;

class Node_variable : public Node {
private:
	list<string> names;
	string initValue;
	string type;
	string lowerBound;
	string upperBound;
public:
	Node_variable(list<Lexeme>::iterator it);
	~Node_variable();

//methods
	void createScalaire(list<string> names, string initValue, string type);
	void createComposite(list<string> names, string initValue, string type, string lowerBound, string upperBound);
	void createStruct();
	bool checkStruct();
	string  displaySonsAndAttributes() const ;
};

#endif 
