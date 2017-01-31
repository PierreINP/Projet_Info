#include "./../Header/Node_architecture.h"

//builders
	Node_architecture::Node_architecture(list<Lexeme>::iterator it, list<Lexeme>::iterator itEnd):Node("Architecture",it), end_it(itEnd){
		cout << "--- Begin of creation : " << getLabel()<< endl;
		createStruct();
		createSons();
		shapeStruct();
		checkStruct();
		cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_architecture::~Node_architecture(){}

//methods
	void Node_architecture::createSons(){
		/*list<Lexeme>::iterator iter;
		list<Lexeme>::iterator tmp_it;

		for (iter = structure.begin(); iter != structure.end(); iter++){
			if(((*iter).getName() == "port") and ((*iter).getType() == "keyword")){
				cout <<"	>>> Add Entity son : port"<< endl;
				sons.push_back(new Node_port(iter));
			}
		}*/
	}

	void Node_architecture::createStruct(){
		list<Lexeme>::iterator it;
	
		for (it = lex_it; it != end_it; it++){
			structure.push_back((*it).getName());
		}
	}

	void Node_architecture::shapeStruct(){
		cutStruct(Lexeme("is"),Lexeme("begin"));
		insertInStruct(Lexeme("begin"),Lexeme("declaration"));
		cutStruct(Lexeme("process"),Lexeme("process"));
	}

	bool Node_architecture::checkStruct(){list<Lexeme>::iterator it;
		list<Lexeme>::iterator it_tmp;
		int step = 0;

		for(it = structure.begin(); it != structure.end(); it ++)
		{
			it_tmp = it;
			cout << step << " | " << *it <<endl;
	///////////////////////////////////////////CHECKSTRUCTURE ARCHITECTURE///////////////////////////////////////////
			switch(step){		
				case 0:		if((*it).getName()=="architecture"){step++;}
						else step=-1;	//rentre dans le cas default
						break;

				case 1:		if((*it).getType()== "id" ){
							architecture_ID = (*it).getName();
							step++;
						}
						else step=-1;
						break;

				case 2:		if((*it).getName()=="of"){step++;}
						else step=-1;
						break;

				case 3:		if((*it).getType()== "id" ){
							entity_ID = (*it).getName();
							step++;
						}
						else step=-1;
						break;
				case 4:		if((*it).getName()=="is"){step++;}
						else step=-1;
						break;

				case 5:		if((*it).getName()=="begin"){step++;}
						else step=-1;
						break;


				case 6:		if((*it).getName()=="end"){step++;}
						else step=-1;
						break;


				case 7:		if((*it).getType()== "id" ){
							if ((*it).getName()==architecture_ID)
								step++;
							else step = -1;						}
						else step=-1;
						break;

				case 8 :        if((*it).getName()==";"){
							cout << "Structure ARCHITECTURE validée" << endl; 
							return true;
						}
						else {return false;}    
					

				default :	cout << "error" << endl; //cf gestion d'erreur
						return false;		  
			}

		}
	}

//accessors
	const string & Node_architecture::getEntityID()const{return entity_ID;}
	const string & Node_architecture::getArchitectureID()const{return architecture_ID;}



