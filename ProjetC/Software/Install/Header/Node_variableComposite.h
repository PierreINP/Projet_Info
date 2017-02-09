#ifndef _NODE_VARIABLECOMPOSITE_H_
#define _NODE_VARIABLECOMPOSITE_H_

#include "Node.h"

using namespace std;

class Node_variableComposite : public Node {
private:
	
public:
	string name;
	string initValue;
	string type;
	string lowerBound;
	string upperBound;
	Node_variableComposite(list<Lexeme>::iterator it,string n, string iV, string t, string lB, string uB);
	~Node_variableComposite();

//methods
	void createStruct();
	bool checkStruct();
	string wrondBoundaries() const;
	string toString() const;

//accessors
	const string & getName()const;
	const string & getInitValue()const;
	const string & getType()const;
	const string & getLowerBound()const;;
	const string & getUpperBound()const;;
};

#endif 
