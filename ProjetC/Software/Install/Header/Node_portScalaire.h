#ifndef _NODE_PORTSCALAIRE_H_
#define _NODE_PORTSCALAIRE_H_

#include "Node.h"

using namespace std;

class Node_portScalaire : public Node {
private:
	
public:
	string name;
	string direction;
	string type;
	Node_portScalaire(list<Lexeme>::iterator it,string n, string d, string t);
	~Node_portScalaire();

//methods
	void createStruct();
	bool checkStruct(); 
	string toString() const;

//accessors
	const string & getName()const;
	const string & getDirection()const;
	const string & getType()const;
};

#endif 
