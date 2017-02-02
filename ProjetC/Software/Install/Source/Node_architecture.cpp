#include "./../Header/Node_architecture.h"
#include "./../Header/Node_declaration.h"
#include "./../Header/Node_process.h"
#include "./../Header/Node_assignment.h"

//builders
	Node_architecture::Node_architecture(list<Lexeme>::iterator it, list<Lexeme>::iterator itEnd):Node("Architecture",it), end_it(itEnd){
		//cout << "--- Begin of creation : " << getLabel()<< endl;
		createStruct();
		createSons();
		shapeStruct();
		checkStruct();
		//cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_architecture::~Node_architecture(){}

//methods
	void Node_architecture::createSons(){
		list<Lexeme>::iterator it;
		list<Lexeme>::iterator it_tmp;
		list<Lexeme>::iterator it_bypass;

		for (it = structure.begin(); it != structure.end(); it++){
			it_tmp = it;

			if((*it).getName()=="is"){
				if ((*++it_tmp).getName()=="signal"
				   or(*it_tmp).getName()=="variable" 
				   or(*it_tmp).getName()=="component" 
				   or(*it_tmp).getName()=="type"){
					cout <<"	>>> Add Architecture son : declaration"<< endl;
					sons.push_back(new Node_declaration(++it));
				}	
			}

			else if(((*it).getName() == "process") and ((*it).getType() == "keyword")){
				cout <<"	>>> Add Architecture son : process"<< endl;
				sons.push_back(new Node_process(it));
				do {it++;}
				while((*it).getName() != "process");
			}

			else if((*it).getType() == "id"){
				if ((*++it_tmp).getName()=="<="){
					cout <<"	>>> Add Architecture son : assignment "<< (*it).getName() << endl;
					sons.push_back(new Node_assignment(it));
				}
				else if ((*it_tmp).getName()==":" and (*++it_tmp).getName() == "="){
					cout <<"	>>> Add Architecture son : assignment "<< (*it).getName() << endl;
					sons.push_back(new Node_assignment(it));
				}
			}
		}

		if (sons.size() == 0){
			cout<< getLabel()<< " has no son"<< endl;
		}
	}

	void Node_architecture::createStruct(){
		list<Lexeme>::iterator it;
	
		for (it = lex_it; it != end_it; it++){
			structure.push_back((*it).getName());
		}
	}

	void Node_architecture::shapeStruct(){
		list<Lexeme>::iterator it;
		list<Lexeme>::iterator it_tmp;

		cutStruct(Lexeme("process"),Lexeme("process"));

		for (it = structure.begin(); it != structure.end(); it++){
			it_tmp = it;

			if((*it).getName()=="is"){
				if ((*++it_tmp).getName()=="signal"
				   or(*it_tmp).getName()=="variable" 
				   or(*it_tmp).getName()=="component" 
				   or(*it_tmp).getName()=="type"){
					cutStruct(Lexeme("is"),Lexeme("begin"));
					structure.insert(++it,Lexeme("declaration"));
				}
				else
					cutStruct(Lexeme("is"),Lexeme("begin"));	 
			}		
		}	
	}

	bool Node_architecture::checkStruct(){
		list<Lexeme>::iterator it;
		list<Lexeme>::iterator it_tmp;
		int step = 0;

		for(it = structure.begin(); it != structure.end(); it ++)
		{
			it_tmp = it;
			cout << step << " | " << *it <<endl;
	///////////////////////////////////////////CHECKSTRUCTURE ARCHITECTURE///////////////////////////////////////////
			switch(step){		
				case 0:		if((*it).getName()=="architecture"){step++;}
						else {
							step=-1;
							cout << "L'architecture ne commence pas par architecture !" << endl;
						}	//rentre dans le cas default
						break;

				case 1:		if((*it).getType()== "id" ){
							architecture_ID = (*it).getName();
							step++;
						}
						else {
							step=-1;
							cout << "Il faut un ID valide après architecture!" << endl;
						}
						break;

				case 2:		if((*it).getName()=="of"){step++;}
						else {
							step=-1;
							cout << "Il faut of dans la déclaration d'une architecture!" << endl;
						}
						break;

				case 3:		if((*it).getType()== "id" ){
							entity_ID = (*it).getName();
							step++;
						}
						else {
							step=-1;
							cout << "Il faut un ID pour associer une entité dans la déclaration d'une architecture!" << endl;
						}
						break;

				case 4:		if((*it).getName()=="is" and (*++it_tmp).getName()=="begin"){step++;}
						else if((*it).getName()=="is" or (*++it_tmp).getName()=="declaration"){step = 9;}
						else {
							step=-1;
							cout << "Il faut is pour finir la déclaration d'une architecture!" << endl;
						}
						break;

				case 5:		if((*it).getName()=="begin" and (*++it_tmp).getName()!="end"){step = 9;}//ca va en step 10
						if((*it).getName()=="begin" or (*++it_tmp).getName()=="end"){step++;}
						else {
							step=-1;
							cout << "Il manque le begin d'une architecture!" << endl;
						}
						break;
					
				case 9:		if((*it).getName()=="declaration"){step = 5;}
						else {
							step=-1;
							cout << "On s'attendait à une déclatation entre is et begin !" << endl;
						}
						break;

				case 10:	if((*it).getName()!="end"){
							//On passe les blocs dans le process Assig, Proccess, If, Case ...
						}
						else if((*it).getName()=="end"){step = 7;}
						else {
							step=-1;
							cout << "On termine une architecture par end process; !" << endl;
						}
						break;

				///////////////////FIN DE FSM///////////////////
				case 6:		if((*it).getName()=="end"){step++;}
						else {
							step=-1;
							cout << "On termine une architecture par end process; !" << endl;
						}
						break;

				case 7:		if((*it).getType()== "id" ){
							if (architecture_ID == (*it).getName())//part of context
								step++;
							else {
							step=-1;
							cout << "On termine une architecture par end process; !" << endl;
							}
						}
						break;

				case 8 :        if((*it).getName()==";"){cout << "Structure ARCHITECTURE validée" << endl; return true;}
						else {cout << "On termine une architecture par end process; !" << endl; return false;}    

				default :	cout << "error" << endl; //cf gestion d'erreur
						return false;		  
			}

		}
	}

//accessors
	const string & Node_architecture::getEntityID()const{return entity_ID;}
	const string & Node_architecture::getArchitectureID()const{return architecture_ID;}



