#ifndef ENTITY_H
#define ENTITY_H

#include "./../Header/Node.h"

using namespace std;

class Entity : virtual Node{
private:
	char label;
	char entity_id;
	liste<Lexeme> structure;
	vector <Node*> enfants;
public:
	Node(list<Lexeme> struc);
	virtual ~Node();

//methods
	void addSon(const *Node enfant);
	void delSon(const *Node enfant);
	Node* accessSon(const *Node enfant)
	Node* nextSon()
	Node* previousSon()
	bool checkStruct(); 

//accessors
	char getlabel();
	char getEntityID();
	liste<Lexeme> getStructure();
};

#endif 
