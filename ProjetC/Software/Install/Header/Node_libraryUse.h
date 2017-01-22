#ifndef _NODE_LIBRARYUSE_H_
#define _NODE_LIBRARYUSE_H_

#include "Node.h"

using namespace std;

class Node_libraryUse : public Node {
private:
	string library_ID;
	string package;
public:
	Node_libraryUse(list<Lexeme> parsing, list<Lexeme>::iterator it);
	~Node_libraryUse();

//methods
	void createSons();
	void createStruct(list<Lexeme> parsing);
	bool checkStruct();

//accessors
	const string & getLibraryID()const;
	const string & getPackage()const;
};

#endif 
