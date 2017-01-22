#include "./../Header/Node_root.h"
#include "./../Header/Node_library.h"
#include "./../Header/Node_entity.h"
#include "./../Header/Node_architecture.h"


//builders
Node_root::Node_root(list<Lexeme> parsing, list<Lexeme>::iterator it):Node("Root",it){
	structure = parsing;
	createSons();
}
Node_root::~Node_root(){}

//methods
void Node_root::createSons(){
	list<Lexeme>::iterator iter;

	for (iter = structure.begin(); iter != structure.end(); iter++){
		if(((*iter).getName() == "library") and ((*iter).getType() == "keyword")){
			cout << endl <<"add son library"<< endl;
			enfants.push_back(new Node_library(structure,iter));
		}
		else if((*iter).getName() == "entity" and ((*iter).getType() == "keyword")){
			cout << endl <<"add son entity"<< endl;
			enfants.push_back(new Node_entity(structure,iter));
		}
		else if((*iter).getName() == "architecture" and ((*iter).getType() == "keyword")){
			cout << endl <<"add son architecture"<< endl;
			enfants.push_back(new Node_architecture(structure,iter));
		}	
		else{
			cout << "x";
		}
	}
}

bool Node_root::checkStruct(){}
void Node_root::createStruct(list<Lexeme> parsing){}

