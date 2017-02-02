#ifndef _NODE_SIGNALCOMPOSITE_H_
#define _NODE_SIGNALCOMPOSITE_H_

#include "Node.h"

using namespace std;

class Node_signalComposite : public Node {
private:
	
public:
	string name;
	string initValue;
	string type;
	string lowerBound;
	string upperBound;
	Node_signalComposite(list<Lexeme>::iterator it,string n, string iV, string t, string lB, string uB);
	~Node_signalComposite();

//methods
	void createStruct();
	bool checkStruct();
//accessors
	const string & getName()const;
	const string & getInitValue()const;
	const string & getType()const;
	const string & getLowerBound()const;;
	const string & getUpperBound()const;;
};

#endif 
