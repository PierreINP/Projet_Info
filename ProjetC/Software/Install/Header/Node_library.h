#ifndef _NODE_LIBRARY_H_
#define _NODE_LIBRARY_H_

#include "Node.h"

using namespace std;

class Node_library : public Node {
private:
	string library_ID;
public:
	Node_library();
	~Node_library();

//methods
	void createSons();
	bool checkStruct();

//accessors
	const string & getLibraryID()const;
};

#endif 
