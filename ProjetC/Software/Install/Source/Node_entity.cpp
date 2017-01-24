#include "./../Header/Node_entity.h"

//builders
Node_entity::Node_entity(list<Lexeme>::iterator it):Node("Entity",it){
//	createSons()
	createStruct();
}
Node_entity::~Node_entity(){}

//methods

void Node_entity::createSons(){}

void Node_entity::createStruct(){
	list<Lexeme>::iterator it;
	for (it = lex_it; (*it).getName() != "architecture"; it++){
		if(((*it).getName() == "port") and ((*it).getType() == "keyword")){
			while(((*it).getName() != "end") or ((*it).getType() != "keyword")){
				it++;
			}
			structure.push_back(Lexeme("port"));
		}
		structure.push_back((*it).getName());
	}
	cout << displayStruct() << endl << endl;
}
bool Node_entity::checkStruct(){
	/*list<Lexeme>::iterator it;
	int step = 0;

	for (it = structure.begin(); it != structure.end(); it++){//parcours de la structure de lexeme locale	

		switch(step){		//FSM struct entity

			case 0:		if(it.getName()=="entity"){step++;}
					else step=-1;	//rentre dans le cas default
			
					break;

			case 1:		if(it.getType()=="id"){
						entity_ID = it.getName();
						step ++;
					}
					else step=-1;
					break;

			case 2 :   	if(it.getName()=="is"){step++;}
					else step=-1;
					break;

			case 3 :        if(it.getName()=="port"){
						//appel methode checkStruct de port ?
						step++;
					}
					else step=-1
					break;
	

			case 4 :        if(it.getName()=="end"){step++;}
					else step=-1;
					break;

			case 5 :        if(it.getName()==entity_ID){step++;}
					else step=-1;
					break;

			case 6 :        if(it.getName()==";"){step++;}
					else step=-1;
					break;

			case 7 :        return true;

			default :	cout << "error" << endl; //cf gestion d'erreur
					return false;		  
		}
	}*/
}

//accessors
const string & Node_entity::getEntityID() const{
	return entity_ID;
}

