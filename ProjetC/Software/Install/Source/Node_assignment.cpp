#include "./../Header/Node_assignment.h"


//builders
	Node_assignment::Node_assignment(list<Lexeme>::iterator it):Node("Assignement",it){
		cout << "--- Begin of creation : " << getLabel()<< endl;
		createStruct();
		checkStruct();
		cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_assignment::~Node_assignment(){}

//methods
	void Node_assignment::createSons(){
	}

	void Node_assignment::createStruct(){
	}

	bool Node_assignment::checkStruct(){
		list<Lexeme>::iterator it;
		list<Lexeme>::iterator it_tmp;
		int step = 0;


		for(it = structure.begin(); it != structure.end(); it ++)
		{
			it_tmp = it;
			cout << step << " | " << *it <<endl;

	///////////////////////////////////////////CHECKSTRUCTURE ASSIGNATION///////////////////////////////////////////
			switch(step){		
				case 0:		if((*it).getType()=="id"){
							step++;
							//GetType ?  Futur test de cohérence de type
						}
						else step=-1;	//rentre dans le cas default
			
						break;

				case 1 : 	if((*it).getName()=="<="){step++;}
						else step=-1;
						break;  	

				//Case 2 et 3 parcourt les Id avant le ":"
				case 2 :   	if((*it).getType()=="id" and (*++it_tmp).getType()=="operator"){
							//recuperer id
							step++;
						}
						else if ((*it).getType()=="id" or (*++it_tmp).getName() == ";") {step = 4;}
						else step=-1;
						break;

				case 3 :       if((*it).getType() == "operator" and (*++it_tmp).getType()=="id"){
							//recuperer opérator
							step--;
						}
						else step=-1;
						break;

					//Fin de l'assignation
				case 4 :        if((*it).getName()==";") {
							cout << "Structure ASSIGNATION validée" << endl; return true;
						}
						else step=-1;
						break;

				default :	cout << "error" << endl; //cf gestion d'erreur
						return false;		  
			}
		}
	}


