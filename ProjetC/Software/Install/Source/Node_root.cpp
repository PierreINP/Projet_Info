#include "./../Header/Node_root.h"
#include "./../Header/Node_library.h"
#include "./../Header/Node_entity.h"
#include "./../Header/Node_architecture.h"


//builders
Node_root::Node_root(list<Lexeme>::iterator it):Node("Root",it){
	createSons();
}
Node_root::~Node_root(){}

//methods
void Node_root::createSons(){
	list<Lexeme> fakeStruct;
	list<Lexeme>::iterator iter;
	Lexeme lex1("Library");
	Lexeme lex2("is");
	Lexeme lex3("Entity");
	Lexeme lex4("Architecture");
	fakeStruct.push_back(lex1);
	fakeStruct.push_back(lex2);
	fakeStruct.push_back(lex3);
	fakeStruct.push_back(lex4);
	for (iter = fakeStruct.begin(); iter != fakeStruct.end(); iter++){
		if((*iter).getName() == "library"){
			cout << "add son library"<< endl;
			enfants.push_back(new Node_library(iter));
		}
		else if((*iter).getName() == "entity"){
			cout << "add son entity"<< endl;
			enfants.push_back(new Node_entity(iter));
		}
		else if((*iter).getName() == "architecture"){
			cout << "add son architecture"<< endl;
			enfants.push_back(new Node_architecture(iter));
		}	
		else{
			cout << "current lex is not one attented to create an instance" << endl;
		}
	}
}

bool Node_root::checkStruct(){}


