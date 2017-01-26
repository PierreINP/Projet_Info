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
//List for port test
	structure.push_back(Lexeme("variable"));
	structure.push_back(Lexeme("a"));
	structure.push_back(Lexeme(","));
	structure.push_back(Lexeme("b"));
	structure.push_back(Lexeme(":"));
	structure.push_back(Lexeme("std_logic_vector"));
	structure.push_back(Lexeme("range"));
	structure.push_back(Lexeme("0"));
	structure.push_back(Lexeme("to"));
	structure.push_back(Lexeme("10"));
	structure.push_back(Lexeme(";"));
	
	list<Lexeme>::iterator it;
	list<Lexeme>::iterator it_tmp;
	int step = 0;


		for(it = structure.begin(); it != structure.end(); it ++)
	{
		it_tmp = it;
		cout << step << " | " << *it <<endl;

///////////////////////////////////////////CHECKSTRUCTURE VARIABLE///////////////////////////////////////////
		switch(step){		
			case 0:		if((*it).getName()=="variable"){step++;}
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

			//Détermination du type du port
			case 4 :        if((*it).getName()== "bit"){
						//port(s)'s type = bit;
						step =7;
					}
					if((*it).getName()== "std_logic"){
						//port(s)'s type = std_logic;
						step =7;
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
			
			//Fin du SIGNAL
			case 7 :        if((*it).getName()==";") {
						cout << "Structure VARIABLE validée" << endl; return true;
					}
					else step=-1;
					break;
			
			//Type composite
			
			case 10 :       if((*it).getName()=="range"){step = 16;} 
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

			case 14 :       if((*it).getName()== ")"){
						//récupération de l'entier
						step =7;
					}
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
						step = 7;
					}
					else step=-1;
					break;

			default :	cout << "error" << endl; //cf gestion d'erreur
					return false;		  
		}
	}
}

