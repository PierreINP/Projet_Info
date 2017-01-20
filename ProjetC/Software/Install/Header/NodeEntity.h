#ifndef ENTITY_H
#define ENTITY_H

#include "./../Header/Node.h"

using namespace std;

class Entity : virtual Node{
private:
	string label;
	string entity_ID;
	list<Lexeme> structure;
	list <Node*> enfants;
public:
	Entity(string e_ID,list<Lexeme> struc);
	//virtual ~Entity();

//methods

//accessors
	string getEntityID();
};

#endif 
