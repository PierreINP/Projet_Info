#ifndef _NODE_SIGNALSCALAIRE_H_
#define _NODE_SIGNALSCALAIRE_H_

#include "Node.h"

using namespace std;

class Node_signalScalaire : public Node {
private:
	
public:
	string name;
	string initValue;
	string type;
	Node_signalScalaire(list<Lexeme>::iterator it,string n, string iV, string t);
	~Node_signalScalaire();

//methods
	void createStruct();
	bool checkStruct(); 
//accessors
	const string & getName()const;
	const string & getInitValue()const;
	const string & getType()const;
};

#endif 
