#ifndef ENTITY_H
#define ENTITY_H

#include "./../Header/Node.h"

using namespace std;

class Entity : virtual Node{
private:
	string label;
	string entity_ID;
	list<Lexeme> structure;
	vector <Node*> enfants;
public:
	Entity(string e_ID,list<Lexeme> struc);
	virtual ~Entity();

//methods
	void addSon(Node* enfant);
	//void delSon(*Node enfant);
	//Node* accessSon(*Node enfant)
	//Node* nextSon()
	//Node* previousSon()
	//bool checkStruct(); 

//accessors
	string getLabel();
	string getEntityID();
	list<Lexeme> getStructure();
};

#endif 
