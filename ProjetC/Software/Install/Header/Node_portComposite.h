#ifndef _NODE_PORTCOMPOSITE_H_
#define _NODE_PORTCOMPOSITE_H_

#include "Node.h"

using namespace std;

class Node_portComposite : public Node {
private:
	
public:
	string name;
	string direction;
	string type;
	string lowerBound;
	string upperBound;
	Node_portComposite(list<Lexeme>::iterator it,string n, string d, string t, string lB, string uB);
	~Node_portComposite();

//methods
	void createStruct();
	bool checkStruct();
	string toString() const;
//accessors
	const string & getName()const;
	const string & getDirection()const;
	const string & getType()const;
	const string & getLowerBound()const;;
	const string & getUpperBound()const;;
};

#endif 
