#include"./../Header/Lexeme.h"

#include <stdlib.h>
#include <stdio.h>
#include <list> 
#include <iostream>
#include <string.h>

using namespace std;
 
extern string keywordList[];
extern char specialList[];
extern string operatorList[];
    
bool isEntier(string a) {
	int i;
	for (i; i< a.size(); i++) {
		if (not(a[i] >= 48 and a[i] <= 57)) {return false;} 
	}
return true;
}


int main() {

	list<Lexeme> structure;
//List for component test
	structure.push_back(Lexeme("component"));
	structure.push_back(Lexeme("compteur"));
	structure.push_back(Lexeme("port"));
	structure.push_back(Lexeme("("));

	structure.push_back(Lexeme("a"));
	structure.push_back(Lexeme(","));
	structure.push_back(Lexeme("b"));
	structure.push_back(Lexeme(":"));
	structure.push_back(Lexeme("in"));
	structure.push_back(Lexeme("std_logic"));
	structure.push_back(Lexeme(";"));

	structure.push_back(Lexeme("cin"));
	structure.push_back(Lexeme(":"));
	structure.push_back(Lexeme("in"));
	structure.push_back(Lexeme("std_logic_vector"));
	structure.push_back(Lexeme("("));
	structure.push_back(Lexeme("0"));
	structure.push_back(Lexeme("downto"));
	structure.push_back(Lexeme("31"));
	structure.push_back(Lexeme(")"));

	structure.push_back(Lexeme(")"));
	structure.push_back(Lexeme(";"));

	structure.push_back(Lexeme("end"));
	structure.push_back(Lexeme("component"));
	structure.push_back(Lexeme(";"));

	
	list<Lexeme>::iterator it;
	list<Lexeme>::iterator it_tmp;
	int step = 30;


		for(it = structure.begin(); it != structure.end(); it ++)
	{
		it_tmp = it;
		cout << step << " | " << *it <<endl;

///////////////////////////////////////////CHECKSTRUCTURE COMPONENT///////////////////////////////////////////
		switch(step){	

			case 30:	if((*it).getName()=="component"){step++;}
					else step=-1;	//rentre dans le cas default
			
					break;

			case 31:	if((*it).getType()=="id"){step =0;}
					else step=-1;
					break;
	
			case 0:		if((*it).getName()=="port"){step++;}
					else step=-1;	//rentre dans le cas default
			
					break;

			case 1:		if((*it).getName()=="("){step++;}
					else step=-1;
					break;

			//Case 2 et 3 parcourt les Id avant le ":"
			case 2 :   	if((*it).getType()=="id"  and (*++it_tmp).getName() == ","){
						//recuperer ID dans un port
						step++;
					}
					else if((*it).getType()=="id"  or (*++it_tmp).getName() == ":"){
						//recuperer ID dans un port
						step = 4;
					}
					else step=-1;
					break;

			case 3 :        //Si id après "," on repart en 2. 
					if((*++it_tmp).getType()=="id") {step--;}
					else step=-1;
					break;
	

			case 4 :     	if((*it).getName()==":"){step++;}
					else step=-1;
					break;

			case 5 :        if((*it).getName()== "in"){
						//port(s) direction = in
						step++;
					}
					else if((*it).getName()== "out"){
						//port(s) direction = out
						step++;
					}
					else step=-1;
					break;
	
			//Détermination du type du port
			case 6 :        if((*it).getName()== "bit"){
						//port(s)'s type = bit;
						step++;
					}
					else if((*it).getName()== "std_logic"){
						//port(s)'s type = std_logic;
						step++;
					}
					else if((*it).getName()== "bit_vector"){
						//port(s)'s type = std_logic_vector;
						step = 10;
					}
					else if((*it).getName()== "std_logic_vector"){
						//port(s)'s type = std_logic_vector;
						step = 10;
					}
					
					else step=-1;
					break;
			//Type scalaire || fin d'un port --> fin de PORT ?
			case 7 :        if((*it).getName()==";"  and (*++it_tmp).getName() == ")"){step = 8;} // si ")" après un port --> fin de PORT
					else if((*it).getName()==";"  or (*++it_tmp).getType() == "id"){step = 2;} // si "id" après un port --> nouveau port
					else step=-1;
					break;
			
			//Type composite
			
			case 10 :       
			//range n'est ok que pour les types entiers, pour signal ou port. Pas pour Port
					if((*it).getName()=="range"){step = -1;} 
					else if((*it).getName() == "("){step++;}
					else step=-1;
					break;

			//Avec up/down to
			case 11 :       if(isEntier((*it).getName())){
						//récupération de l'entier
						step++;
					}
					else step=-1;
					break;

			case 12 :       if((*it).getName()== "upto"){
						//manière de compter
						step++;
					}
					else if((*it).getName()== "downto"){
						//manière de compter
						step++;
					}
					else step=-1;
					break;

			case 13 :       if(isEntier((*it).getName())){
						//récupération de l'entier
						step++;
					}
					else step=-1;
					break;

			case 14 :       if((*it).getName() == ")"){step++;}
					else step=-1;
					break;
						
			case 15 :       if((*it).getName()== ")"){step = 9;}
					else if((*it).getName() == ";" and (*++it_tmp).getType() == "id"){step = 2;}
					else step=-1;
					break;
			
			//Avec range
			case 16 :       if(isEntier((*it).getName())){
						//récupération de l'entier
						step++;
					}
					else step=-1;
					break;

			case 17 :       if((*it).getName()== "to"){
						//manière de compter
						step++;
					}
					else step=-1;
					break;

			case 18 :       if(isEntier((*it).getName())){
						//récupération de l'entier
						step++;
					}
					else step=-1;
					break;

			case 19 :       if((*it).getName()== ")"){step = 9;}
					else if((*it).getName() == ";" and (*++it_tmp).getType() == "id"){step = 2;}
					else step=-1;
					break;


			//FIN DE FSM
			case 8 :        if((*it).getName()==")"){step++;}
					else step=-1;
					break;


			case 9 :        if((*it).getName()==";"){step = 32;}
					else step=-1;
					break;

			case 32 :       if((*it).getName()=="end"){step++;}
					else step=-1;
					break;

			case 33 :       if((*it).getName()=="component"){step++;}
					else step=-1;
					break;


			case 34 :       if((*it).getName()==";"){cout << "Structure COMPONENT validée" << endl; return true;}
					else {return false;} 

   
					

			default :	cout << "error" << endl; //cf gestion d'erreur
					return false;		  
		}
	}
}

