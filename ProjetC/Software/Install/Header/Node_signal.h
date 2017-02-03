#ifndef _NODE_SIGNAL_H_
#define _NODE_SIGNAL_H_

#include "Node.h"

using namespace std;

class Node_signal : public Node {
private:
	list<string> names;
	string initValue;
	string type;
	string lowerBound;
	string upperBound;
public:
	Node_signal(list<Lexeme>::iterator it);
	~Node_signal();

//methods
	void createScalaire(list<string> names, string initValue, string type);
	void createComposite(list<string> names, string initValue, string type, string lowerBound, string upperBound);
	void createStruct();
	bool checkStruct();
	string  displaySonsAndAttributes() const ;
};

#endif 
