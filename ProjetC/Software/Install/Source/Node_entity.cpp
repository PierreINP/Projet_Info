#include "./../Header/Node_entity.h"
#include "./../Header/Node_port.h"

//builders
	Node_entity::Node_entity(list<Lexeme>::iterator it):Node("Entity",it){
		//cout << "--- Begin of creation : " << getLabel()<< endl;
		createStruct();
		createSons();
		shapeStruct();
		checkStruct();
		//cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_entity::~Node_entity(){}

//methods

	void Node_entity::createSons(){	
		list<Lexeme>::iterator iter;

		for (iter = structure.begin(); iter != structure.end(); iter++){
			if(((*iter).getName() == "port") and ((*iter).getType() == "keyword")){
				cout <<"	>>> Add Entity son : port"<< endl;
				sons.push_back(new Node_port(iter));
			}
		}
		if (sons.size() == 0){
			cout<< getLabel()<< " has no son"<< endl;
		}	
	}

	void Node_entity::createStruct(){
		list<Lexeme>::iterator it;
		for (it = lex_it; (*it).getName() != "architecture"; it++){
			structure.push_back((*it).getName());
		}
	}

	void Node_entity::shapeStruct(){
		cutStruct(Lexeme("port"),Lexeme("end"));
	}

	bool Node_entity::checkStruct(){
		list<Lexeme>::iterator it;
		list<Lexeme>::iterator it_tmp;
		int step = 0;
		string entity_ID;

		cout << "** Start ENTITY structure validation ** " << endl;
		for(it = structure.begin(); it != structure.end(); it ++)
		{
			it_tmp = it;
			cout << step << " | " << *it <<endl;
			
			switch(step){		//FSM struct entity
				case 0:		if((*it).getName()=="entity"){step++;}
						else step=-1;	//rentre dans le cas default
						break;

				case 1:		if((*it).getType()=="id"){
							entity_ID = (*it).getName();
							step++;
						}
						else {
							step=-1;
							cout << "mauvais ID pour l'entité !" << endl;
						}
						break;

				case 2 :   	if((*it).getName()=="is"){step++;}
						else {
							step=-1;
							cout << "on attend un ID + is pour l'entité !" << endl;
						}
						break;

				case 3 :        if((*it).getName()=="port"){
							step++;
						}
						else {
							step=-1;
							cout << "L'entité n'a pas de port !" << endl;
						}
						break;
	

				case 4 :     	if((*it).getName()=="end" and (*++it_tmp).getType() == "id"){step++;}
						else if((*it).getName()=="end" or (*++it_tmp).getName() == ";"){step = 6 ;}
						else {
							step=-1;
							cout << "On fini une entité par end (ID); !" << endl;
						}
						break;

				case 5 :        if((*it).getName()==entity_ID){step++;} //Check matching between entity_ID at begin and end of entity bloc : context step
						else {
							step=-1;
							cout << "On fini une entité par end (ID); !" << endl;
						}
						break;

				case 6 :        if((*it).getName()==";"){cout << "Structure ENTITY validée" << endl; return true;}
						else {
							cout << "On fini une entité par end (ID); !" << endl;
							return false;
						}   
					

				default :	cout << "error" << endl; //cf gestion d'erreur
						return false;		  
			}

		}
	}

//accessors
	const string & Node_entity::getEntityID() const{
		return entity_ID;
	}

