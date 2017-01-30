#ifndef _NODE_PORTSIGNAL_H_
#define _NODE_PORTSIGNAL_H_

#include "Node.h"

using namespace std;

class Node_portSignal : public Node {
private:
	
public:
	string name;
	string direction;
	string type;
	int lowerBound;
	int upperBound;
	Node_portSignal(list<Lexeme>::iterator it,string n, string d, string t);//, int lB, int uB);
	~Node_portSignal();

//methods
	void createStruct();
	bool checkStruct(); //Node virtual pure function not used for this class : structure checking is made during parsing

//accessors
	const string & getName()const;
	const string & getDirection()const;
	const string & getType()const;
	int getLowerBound();
	int getUpperBound();

};

#endif 
