#include "./../Header/Node_root.h"
#include "./../Header/Node_library.h"
#include "./../Header/Node_entity.h"
#include "./../Header/Node_architecture.h"


//builders
Node_root::Node_root(list<Lexeme> parsing, list<Lexeme>::iterator it):Node("Root",it){
	cout << endl << "######################"<<endl<<"  Begin tree built  "<< endl<<"######################"<<endl;
	structure = parsing;
	cout << displayStruct() << endl;
	createSons();
	cout << ">>> End of " << getLabel()<< " creation" << endl;
}

Node_root::~Node_root(){}

//methods
void Node_root::createSons(){
	list<Lexeme>::iterator iter;
	list<Lexeme>::iterator iter_endOfList = structure.end();

	for (iter = structure.begin(); iter != structure.end(); iter++){
		if(((*iter).getName() == "library") and ((*iter).getType() == "keyword")){
			cout <<endl<<">>> Add Root son : library"<< endl;
			enfants.push_back(new Node_library(iter));
		}
		else if((*iter).getName() == "entity" and ((*iter).getType() == "keyword")){
			cout <<endl<<">>> Add Root son : entity"<< endl;
			enfants.push_back(new Node_entity(iter));
		}
		else if((*iter).getName() == "architecture" and ((*iter).getType() == "keyword")){
			cout <<endl<<">>> Add Root son : architecture"<< endl;
			enfants.push_back(new Node_architecture(iter,iter_endOfList));
		}	
	}
}

bool Node_root::checkStruct(){} //Node virtual pure function not used for this class
void Node_root::createStruct(){}//Node virtual pure function not used for this class

