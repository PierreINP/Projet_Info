#include "./../Header/Node_signal.h"

//builders
	Node_signal::Node_signal(list<Lexeme>::iterator it):Node("Signal",it){
		cout << "--- Begin of creation : " << getLabel()<< endl;
		createStruct();
		checkStruct();
		cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_signal::~Node_signal(){}

//methods
	void Node_signal::createSons(){
	}

	void Node_signal::createStruct(){
	}

	bool Node_signal::checkStruct(){
		list<Lexeme>::iterator it;
		list<Lexeme>::iterator it_tmp;
		int step = 0;


		for(it = structure.begin(); it != structure.end(); it ++)
		{
			it_tmp = it;
			cout << step << " | " << *it <<endl;

	///////////////////////////////////////////CHECKSTRUCTURE SIGNAL///////////////////////////////////////////
			switch(step){		
				case 0:		if((*it).getName()=="signal"){step++;}
						else step=-1;	//rentre dans le cas default
			
						break;

				//Case 2 et 3 parcourt les Id avant le ":"
				case 1 :   	if((*it).getType()=="id"  and (*++it_tmp).getName() == ","){
							//recuperer ID dans un port
							step++;
						}
						else if((*it).getType()=="id"  or (*++it_tmp).getName() == ":"){
							//recuperer ID dans un port
							step +=2;
						}
						else step=-1;
						break;

				case 2 :        //Si id après "," on repart en 2. 
						if((*++it_tmp).getType()=="id") {step--;}
						else step=-1;
						break;
	

				case 3 :     	if((*it).getName()==":"){step++;}
						else step=-1;
						break;

				//Détermination du type du signal [composite ou scalaire]
				case 4 :       	///////////////////////////////////////////
						//Bit avec initialisation
						if((*it).getName()== "bit") {
							if ((*++it_tmp).getName()== ":"){
							//signal's type = bit;
							step = 10;
							}
							else step = 7;
						}

						///////////////////////////////////////////
						//std_logic avec initialisation
						else if((*it).getName()== "std_logic"){
							if ((*++it_tmp).getName()== ":"){
								//signal)'s type = std_logic;
								step = 15;
							}
							else step = 7;
						}
						///////////////////////////////////////////
						//integer avec initialisation
						else if((*it).getName()== "integer"){
							if ((*++it_tmp).getName()== "range"){
							//signal's type = integer;
							step = 20;
						}
							else step = 7;
						}
						///////////////////////////////////////////
						//string avec initialisation
						else if((*it).getName()== "string"){
							//signal's type = string;
							step = 30;
						}

						///////////////////////////////////////////
						//boolean avec initialisation
						else if((*it).getName()== "boolean") {
							if ((*++it_tmp).getName()== ":"){
								//signal's type = boolean;
								step = 40;
							}
							else step = 7;
						}
						///////////////////////////////////////////
						//bit_vector avec initialisation
						else if((*it).getName()== "bit_vector"){
							//signal's type = bit_vector;
							step = 50;
						}

						///////////////////////////////////////////
						//std_logic_vector avec initialisation
						else if((*it).getName()== "std_logic_vector"){
							//signal's type = std_logic_vector;
							step = 50;
						}
				
						else step = -1;
						break;
			
				//Bit
				case 10 :       if((*it).getName() == ":"){step++;}
						else step=-1;
						break;

				case 11:       if((*it).getName() == "="){step++;}
						else step=-1;
						break;

				case 12 :       if((*it).getName() == "'"){step++;}
						else step=-1;
						break;

				case 13 :       if(isEntier((*it).getName())){
							//récupération de la valeur d'initialisation
							step++;
						}
						else step=-1;
						break;

				case 14 :       if((*it).getName() == "'"){step = 7;}
						else step=-1;
						break;

				//std_logic
				case 15 :       if((*it).getName() == ":"){step++;}
						else step=-1;
						break;

				case 16:       if((*it).getName() == "="){step++;}
						else step=-1;
						break;

				case 17 :       if((*it).getName() == "'"){step++;}
						else step=-1;
						break;

				case 18 :       if(isStd_Logic((*it).getName())){
							//récupération de la valeur d'initialisation
							step++;
						}
						else step=-1;
						break;

				case 19 :       if((*it).getName() == "'"){step = 7;}
						else step=-1;
						break;

			
				//INTEGER avec range
				case 20 :       if((*it).getName() == "range"){step++;}
						else step=-1;
						break;
				case 21 :       if(isEntier((*it).getName())){step++;}
						else step=-1;
						break;

				case 22 :       if((*it).getName()== "to"){
							//manière de compter
							step++;
						}
						else step=-1;
						break;

				case 23 :       if(isEntier((*it).getName()) and (*++it_tmp).getName() == ";"){
							//récupération de l'entier
							step = 7;
						}
						else if(isEntier((*it).getName()) or (*++it_tmp).getName() == ":"){step++;}
						else step=-1;
						break;

				case 24 :       if((*it).getName() == ":"){step++;}
						else step=-1;
						break;

				case 25 :       if((*it).getName() == "="){step++;}
						else step=-1;
						break;

				case 26 :       if(isEntier((*it).getName())){
							//récupération de la valeur d'initialisation
							step = 7;
						}
						else step=-1;
						break;

				//String avec TO
				case 30 :       if((*it).getName() == "("){
							step++;
						}
						else step=-1;
						break;

				case 31 :       if(isEntier((*it).getName())){
							//récupération de l'entier
							step++;
						}
						else step=-1;
						break;

				case 32 :       if((*it).getName()== "to"){
							//manière de compter
							step++;
						}

						else step=-1;
						break;

				case 33 :       if(isEntier((*it).getName())){
							//récupération de l'entier
							step++;
						}
						else step=-1;
						break;

				case 34 :      	if((*it).getName()== ")" and (*++it_tmp).getName() == ";"){
	
							step = 7;
						}
						else if((*it).getName()== ")" or (*++it_tmp).getName() == ":"){

							step++;
						}
						else step=-1;
						break;

				case 35 :       if((*it).getName() == ":"){step++;}
						else step=-1;
						break;

				case 36 :       if((*it).getName() == "="){step++;}
						else step=-1;
						break;

				case 37 :       if((*it).getName() == "\""){step++;}
						else step=-1;
						break;

				case 38 :       if(isString((*it).getName())){
							//récupération de l'entier
							step++;
						}
						else step=-1;
						break;

				case 39 :       if((*it).getName() == "\""){step = 7;}
						else step=-1;
						break;

				//BOOLEAN
				case 40 :       if((*it).getName() == ":"){step++;}
						else step=-1;
						break;

				case 41:       if((*it).getName() == "="){step++;}
						else step=-1;
						break;


				case 42 :       if((*it).getName() == "false"){
							//récupération de la valeur d'initialisation
							step = 7;
						}
						else if((*it).getName() == "true"){
							//récupération de la valeur d'initialisation
							step = 7;
						}
						else step=-1;
						break;


				//VECTOR avec up/down
				case 50 :       if((*it).getName() == "("){
							step++;
						}
						else step=-1;
						break;

				case 51 :       if(isEntier((*it).getName())){
							//récupération de l'entier
							step++;
						}
						else step=-1;
						break;

				case 52 :       if((*it).getName()== "upto"){
							//manière de compter
							step++;
						}
						else if((*it).getName()== "downto"){
							//manière de compter
							step++;
						}
						else step=-1;
						break;

				case 53 :       if(isEntier((*it).getName())){
							//récupération de l'entier
							step++;
						}
						else step=-1;
						break;

				case 54 :      	if((*it).getName()== ")" and (*++it_tmp).getName() == ";"){step = 7;}
						else if((*it).getName()== ")" or (*++it_tmp).getName() == ":"){step++;}
						else step=-1;
						break;

				case 55 :       if((*it).getName() == ":"){step++;}
						else step=-1;
						break;

				case 56 :       if((*it).getName() == "="){step++;}
						else step=-1;
						break;

				case 57 :       if((*it).getName() == "\""){step++;}
						else step=-1;
						break;

				case 58 :       if(isEntier((*it).getName())){
							//récupération de l'entier
							step++;
						}
						else step=-1;
						break;

				case 59 :       if((*it).getName() == "\""){step = 7;}
						else step=-1;
						break;

				//Fin du SIGNAL
				case 7 :        if((*it).getName()==";") {
							cout << "Structure SIGNAL validée" << endl; return true;
						}
						else step=-1;
						break;

				default :	cout << "error" << endl; //cf gestion d'erreur
						return false;		  
			}
		}
	}



