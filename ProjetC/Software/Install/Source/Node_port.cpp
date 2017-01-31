#include "./../Header/Node_port.h"
#include "./../Header/Node_portScalaire.h"
#include "./../Header/Node_portComposite.h"


//builders
	Node_port::Node_port(list<Lexeme>::iterator it):Node("Port",it){
		cout << "--- Begin of creation : " << getLabel()<< endl;
		createStruct();
		checkStruct();
		cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_port::~Node_port(){}

//methods

	void Node_port::createScalaire(list<string> names, string direction, string type){
		list<string>::iterator it;
	
		for(it = names.begin(); it != names.end(); it++){
			sons.push_back(new Node_portScalaire(lex_it,*it,direction,type));
		}
	}

	void Node_port::createComposite(list<string> names, string direction, string type, string lowerBound, string upperBound){
		list<string>::iterator it;
	
		for(it = names.begin(); it != names.end(); it++){
			sons.push_back(new Node_portComposite(lex_it,*it,direction,type, lowerBound,upperBound));
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

		bool countWay;
		string tmpBound;
		int step = 0;
		

		//cout << "   ** Start PORT structure validation **   "<< endl;
		for(it = structure.begin(); it != structure.end(); it ++){
			it_tmp = it;
			cout << step << " | " << *it <<endl;

			switch(step){		
				case 0:		if((*it).getName()=="port")	{step++;}
						else 				{step=-1;} //go to default case 
						break;

				case 1:		if((*it).getName()=="(")	{step++;}
						else 				{step=-1;}
						break;

				
				//Case 2 et 3 retrieve IDs before ':' lexeme 
				case 2 :   	if((*it).getType()=="id"){
							names.push_back((*it).getName());
							if((*++it_tmp).getName() == ",")	{step++;}
							else if((*++it_tmp).getName() != ":")	{step=4;}
							else 					{step=-1;}
						}
						break;

				case 3 :        //Go back to case 2 if ID after "," 
						if((*++it_tmp).getType()=="id") 	{step--;}
						else 					{step=-1;}
						break;

				case 4 :     	if((*it).getName()==":")		{step++;}
						else 					{step=-1;}
						break;

				case 5 :       if((*it).getName()== "in"){		step++;
							direction = "in"; 
						}
						else if((*it).getName()== "out"){	
							direction = "out";
							step++;
						}
						else step=-1;
						break;

				//Détermination du type du port
				case 6 :        if((*it).getName()== "bit"){
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
				case 7 :        createScalaire(names,direction,type); //end of line : creation of scalaire port
						names.clear();
						direction.clear();
						type.clear();
						if((*it).getName()==";"  and (*++it_tmp).getName() == ")"){step = 8;} // si ")" après un port --> fin de PORT
						else if((*it).getName()==";"  or (*++it_tmp).getType() == "id"){step = 2;} // si "id" après un port --> nouveau port
						else step=-1;
						break;
		
				//Type composite
		
				case 10 :       if((*it).getName()=="range"){step = 16;} 
						else if((*it).getName() == "("){step++;}
						else step=-1;
						break;

				//Avec up/down to
				case 11 :       if(isEntier((*it).getName())){
							lowerBound = (*it).getName();
							step++;
						}
						else step=-1;
						break;

				case 12 :       if((*it).getName()== "upto"){
							countWay = false;
							step++;
						}
						else if((*it).getName()== "downto"){
							countWay = true;
							step++;
						}
						else step=-1;
						break;

				case 13 :       if(isEntier((*it).getName())){
							upperBound = (*it).getName();
							step++;
						}
						else step=-1;
						break;

				case 14 :       if((*it).getName() == ")"){step++;}
						else step=-1;
						break;
					
				case 15 :       if (countWay){ //if range is downto type ; exchange upper and lower Bounds
							tmpBound=lowerBound; 
							lowerBound = upperBound;
							upperBound = tmpBound;
						}
						createComposite(names,direction,type,lowerBound,upperBound);//end of line : creation of composite port
						names.clear();
						direction.clear();
						type.clear();
						lowerBound.clear();
						upperBound.clear();
						if((*it).getName()== ")"){step = 9;}
						else if((*it).getName() == ";" and (*++it_tmp).getType() == "id"){step = 2;}
						else step=-1;
						break;
		
				//Avec range
				case 16 :       if(isEntier((*it).getName())){
							lowerBound = (*it).getName();
							step++;
						}
						else step=-1;
						break;

				case 17 :       if((*it).getName()== "to"){
							step++;
						}
						else step=-1;
						break;

				case 18 :       if(isEntier((*it).getName())){
							upperBound = (*it).getName();
							step=15;
						}
						else step=-1;
						break;

				//FIN DE FSM
				case 8 :        if((*it).getName()==")"){step++;}
						else step=-1;
						break;

				case 9 :        if((*it).getName()==";"){
							cout << "	Structure PORT validée" << endl;
							return true;
						}
						else return false;    
				

				default :	cout << "error" << endl; //cf gestion d'erreur
						return false;		  
			}
		}
	}



