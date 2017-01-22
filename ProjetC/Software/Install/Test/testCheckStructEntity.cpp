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
	
//List for entity test
/*
	structure.push_back(Lexeme("entity"));
	structure.push_back(Lexeme("toto"));
	structure.push_back(Lexeme("is"));
	structure.push_back(Lexeme("port"));	
	structure.push_back(Lexeme("end"));
	structure.push_back(Lexeme("toto"));
	structure.push_back(Lexeme(";"));
*/
//List for port test
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
	structure.push_back(Lexeme(";"));

	structure.push_back(Lexeme("cout"));
	structure.push_back(Lexeme(":"));
	structure.push_back(Lexeme("out"));
	structure.push_back(Lexeme("bit_vector"));
	structure.push_back(Lexeme("range"));
	structure.push_back(Lexeme("0"));
	structure.push_back(Lexeme("to"));
	structure.push_back(Lexeme("31"));
	structure.push_back(Lexeme(""));

	structure.push_back(Lexeme(")"));
	structure.push_back(Lexeme(";"));

	
	list<Lexeme>::iterator it;
	list<Lexeme>::iterator it_tmp;
	int step = 0;
	string entity_ID;


		for(it = structure.begin(); it != structure.end(); it ++)
	{
		it_tmp = it;
		cout << *it << " | " << step <<endl;
///////////////////////////////////////////CHECKSTRUCTURE ENTITY///////////////////////////////////////////
	/*	switch(step){		//FSM struct entity
			case 0:		if((*it).getName()=="entity"){step++;}
					else step=-1;	//rentre dans le cas default
			
					break;

			case 1:		if((*it).getType()=="id"){
						entity_ID = (*it).getName();
						step++;
					}
					else step=-1;
					break;

			case 2 :   	if((*it).getName()=="is"){step++;}
					else step=-1;
					break;

			case 3 :        if((*it).getName()=="port"){
						//appel methode checkStruct de port ?
						step++;
					}
					else step=-1;
					break;
	

			case 4 :     	if((*it).getName()=="end" and (*++it_tmp).getType() == "id"){step++;}
					else if((*it).getName()=="end" or (*++it_tmp).getName() == ";"){step = 6 ;}
					else step=-1;
					break;

			case 5 :        if((*it).getName()==entity_ID){step++;} //Le fait de tester entityID au lieu de type == ID est deja de l'étape contexte.
					else step=-1;
					break;

			case 6 :        if((*it).getName()==";"){cout << "Structure ENTITY validée" << endl; return true;}
					else {return false;}    
					

			default :	cout << "error" << endl; //cf gestion d'erreur
					return false;		  
		}*/
///////////////////////////////////////////CHECKSTRUCTURE PORT///////////////////////////////////////////
		switch(step){		
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
					if((*it).getName()== "std_logic"){
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
			case 7 :        if((*it).getName()==";"  and (*++it_tmp).getName() == ")"){step++;} // si ")" après un port --> fin de PORT
					else if((*it).getName()==";"  or (*++it_tmp).getType() == "id"){step = 2;} // si "id" après un port --> nouveau port
					else step=-1;
					break;
			
			//Type composite
			
			case 10 :       if((*it).getName()=="range"){step = 15;} 
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

			case 14 :       if(isEntier((*it).getName())  and (*++it_tmp).getName() == ";"){step = 2;}
					else if((*it).getName() == ")"  and (*++it_tmp).getName() == ")"){step = 8;}
					else step=-1;
					break;
			
			//Avec range
			case 15 :       if(isEntier((*it).getName())){
						//récupération de l'entier
						step++;
					}
					else step=-1;
					break;

			case 16 :       if((*it).getName()== "upto"){
						//manière de compter
						step++;
					}
					else if((*it).getName()== "downto"){
						//manière de compter
						step++;
					}
					else step=-1;
					break;

			case 17 :       if(isEntier((*it).getName())){
						//récupération de l'entier
						step = 7;
					}
					else step=-1;
					break;


			//FIN DE FSM
			case 8 :        if((*it).getName()==")"){step = 9;}
					else step=-1;
					break;

			case 9 :        if((*it).getName()==";"){cout << "Structure PORT validée" << endl; return true;}
					else {return false;}    
					

			default :	cout << "error" << endl; //cf gestion d'erreur
					return false;		  
		}
///////////////////////////////////////////CHECKSTRUCTURE xxxx///////////////////////////////////////////
	}
}

