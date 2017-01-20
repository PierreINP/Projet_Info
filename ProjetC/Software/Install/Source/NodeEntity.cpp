#include "./../Header/Entity.h"
#include <iostream> 


//builders
Entity::Entity(){
	label = "Entity"
}

Entity::Entity(string e_ID,list<Lexeme> struc) {
	label = "Entity"
	entity_ID = e_ID
	structure = struc	
}

Entity::~Entity(){}

//methods


//accessors
	string getLabel(return label);
	string getEntityID(return e_ID);
	liste<Lexeme> getStructure(return structure);

