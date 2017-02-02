#ifndef _NODE_VARIABLESCALAIRE_H_
#define _NODE_VARIABLESCALAIRE_H_

#include "Node.h"

using namespace std;

class Node_variableScalaire : public Node {
private:
	
public:
	string name;
	string initValue;
	string type;
	Node_variableScalaire(list<Lexeme>::iterator it,string n, string iV, string t);
	~Node_variableScalaire();

//methods
	void createStruct();
	bool checkStruct(); 
//accessors
	const string & getName()const;
	const string & getInitValue()const;
	const string & getType()const;
};

#endif 
