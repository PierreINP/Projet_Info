#include "./../Header/Node_port.h"
#include "./../Header/Node_portSignal.h"


//builders
	Node_port::Node_port(list<Lexeme>::iterator it):Node("Port",it){
		cout << "--- Begin of creation : " << getLabel()<< endl;
		createStruct();
		checkStruct();
		cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_port::~Node_port(){}

//methods
	void Node_port::createSons(list<string> names, string direction, string type){//, int lowerBound=0, int upperBound=0){
		list<string>::iterator it;
	
		for(it = names.begin(); it != names.end(); it++){
			cout << *it << " <<< HEEEEERE" << endl << endl; 
			sons.push_back(new Node_portSignal(lex_it,*it,direction,type));//lowerBound,upperBound))
		}	
	}

	void Node_port::createStruct(){
		list<Lexeme>::iterator it;
	
		for (it = lex_it; (*it).getName() != "end"; it++){
			structure.push_back((*it).getName());
		}
	}

	bool Node_port::checkStruct(){
		list<Lexeme>::iterator it;
		list<Lexeme>::iterator it_tmp;
		int step = 0;

		//cout << "   ** Start PORT structure validation **   "<< endl;
		for(it = structure.begin(); it != structure.end(); it ++){
			it_tmp = it;
			//cout << step << " | " << *it <<endl;

			switch(step){		
				case 0:		cout << "Case 0" << endl;
						if((*it).getName()=="port")	{step++;}
						else 				{step=-1;} //go to default case 
						break;

				case 1:		cout << "Case 1" << endl;
						if((*it).getName()=="(")	{step++;}
						else 				{step=-1;}
						break;

				/* NEW VERSION */
				//Case 2 et 3 retrieve IDs before ':' lexeme 
				case 2 :   	cout << "Case 2" << endl;
						if((*it).getType()=="id"){
							names.push_back((*it).getName());
							if((*++it_tmp).getName() == ",")	{cout << "," << endl;
						step++;}
							else if((*++it_tmp).getName() != ":")	{cout << ":" << endl;
						step=4;}
							else 					{step=-1;}
						}
						break;

				case 3 :        cout << "Case 3" << endl;
						//Go back to case 2 if ID after "," 
						if((*++it_tmp).getType()=="id") 	{step--;}
						else 					{step=-1;}
						break;

				case 4 :     	cout << "Case 4" << endl;
						if((*it).getName()==":")		{step++;}
						else 					{step=-1;}
						break;

				case 5 :        cout << "Case 5" << endl;
						if((*it).getName()== "in"){		step++;
							direction = "in"; 
						}
						else if((*it).getName()== "out"){	
							direction = "out";
							step++;
						}
						else step=-1;
						break;

				//Détermination du type du port
				case 6 :        cout << "Case 6" << endl;
						 if((*it).getName()== "bit"){
							type = "bit";
							step++;
						}
						if((*it).getName()== "std_logic"){
							type = "std_logic";
							step++;
						}
						else if((*it).getName()== "bit_vector"){
							type = "bit_vector";
							step = 10;
						}
						else if((*it).getName()== "std_logic_vector"){
							type = "std_logic_vector";
							step = 10;
						}
						else step=-1;
						break;

				//Type scalaire || fin d'un port --> fin de PORT ?
				case 7 :       	cout << "Case 7" << endl;
						createSons(names,direction,type); 
						if((*it).getName()==";"  and (*++it_tmp).getName() == ")"){step = 8;} // si ")" après un port --> fin de PORT
						else if((*it).getName()==";"  or (*++it_tmp).getType() == "id"){step = 2;} // si "id" après un port --> nouveau port
						else step=-1;
						break;
		
				//Type composite
		
				case 10 :       cout << "Case 10" << endl;
						if((*it).getName()=="range"){step = 16;} 
						else if((*it).getName() == "("){step++;}
						else step=-1;
						break;

				//Avec up/down to
				case 11 :       cout << "Case 11" << endl;
						if(isEntier((*it).getName())){
							//récupération de l'entier
							step++;
						}
						else step=-1;
						break;

				case 12 :       cout << "Case 12" << endl;
						if((*it).getName()== "upto"){
							//manière de compter
							step++;
						}
						else if((*it).getName()== "downto"){
							//manière de compter
							step++;
						}
						else step=-1;
						break;

				case 13 :       cout << "Case 13" << endl;
						if(isEntier((*it).getName())){
							//récupération de l'entier
							step++;
						}
						else step=-1;
						break;

				case 14 :       cout << "Case 14" << endl;
						if((*it).getName() == ")"){step++;}
						else step=-1;
						break;
					
				case 15 :       cout << "Case 15" << endl;
						createSons(names,direction,type);
						if((*it).getName()== ")"){step = 9;}
						else if((*it).getName() == ";" and (*++it_tmp).getType() == "id"){step = 2;}
						else step=-1;
						break;
		
				//Avec range
				case 16 :       cout << "Case 16" << endl;
						if(isEntier((*it).getName())){
							//lowerBound = (*it).getName();
							step++;
						}
						else step=-1;
						break;

				case 17 :       cout << "Case 17" << endl;
						if((*it).getName()== "to"){
							//manière de compter
							step++;
						}
						else step=-1;
						break;

				case 18 :       cout << "Case 18" << endl;
						if(isEntier((*it).getName())){
							//upperBound = (*it).getName();
							step++;
						}
						else step=-1;
						break;

				case 19 :       cout << "Case 19" << endl;
						createSons(names,direction,type);
						if((*it).getName()== ")"){step = 9;}
						else if((*it).getName() == ";" and (*++it_tmp).getType() == "id"){step = 2;}
						else step=-1;
						break;


				//FIN DE FSM
				case 8 :        cout << "Case 8" << endl;
						if((*it).getName()==")"){step++;}
						else step=-1;
						break;

				case 9 :        cout << "Case 9" << endl;
						if((*it).getName()==";"){cout << "	Structure PORT validée" << endl; return true;}
						else {return false;}    
				

				default :	cout << "error" << endl; //cf gestion d'erreur
						return false;		  
			}
		}
	}

//accessors
	const list<string> & Node_port::getNames()const{
		return names;
	}

	const string & Node_port::getDirection()const{
		return direction;
	}

	const string & Node_port::getTypeD()const{
		return type;
	}


