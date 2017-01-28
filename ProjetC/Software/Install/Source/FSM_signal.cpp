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
//Vérifie si chaque caractère d'un lexeme est un chiffre
	int i;
	for (i; i< a.size(); i++) {
		if (not(a[i] >= 48 and a[i] <= 57)) {return false;} 
	}
return true;
}

bool isString(string a) {
//Vérifie si chaque caractère d'un lexeme est un chiffre
	int i;
	for (i; i< a.size(); i++) {
		if (not(a[i] >= 97 and a[i] <= 122)) {return false;} 
	}
return true;
}

bool isStd_Logic(string a) {
//Vérifie si chaque caractère d'un lexeme est un type reconnu de std logic
	char tab_type[10] = {"ux01zwlh-"};
	int i;
	for (i=0; i <9; i++) {
		//cout << "LEX " << a[0] << " TYPE? " << tab_type[i] <<endl;
		if(a[0] == tab_type[i]){
			return true;
		}
	}
return false;
}


int main() {

	list<Lexeme> structure;
//List for port test
/*TEST VECTOR
	structure.push_back(Lexeme("signal"));
	structure.push_back(Lexeme("a"));
	structure.push_back(Lexeme(","));
	structure.push_back(Lexeme("b"));
	structure.push_back(Lexeme(":"));
	structure.push_back(Lexeme("bit_vector"));
	structure.push_back(Lexeme("("));
	structure.push_back(Lexeme("0"));
	structure.push_back(Lexeme("upto"));
	structure.push_back(Lexeme("10"));
	structure.push_back(Lexeme(")"));
	structure.push_back(Lexeme(":"));
	structure.push_back(Lexeme("="));
	structure.push_back(Lexeme("\""));
	structure.push_back(Lexeme("0000"));
	structure.push_back(Lexeme("\""));
	structure.push_back(Lexeme(";"));
*/

/*TEST INTEGER
	structure.push_back(Lexeme("signal"));
	structure.push_back(Lexeme("a"));
	structure.push_back(Lexeme(","));
	structure.push_back(Lexeme("b"));
	structure.push_back(Lexeme(":"));
	structure.push_back(Lexeme("integer"));
	structure.push_back(Lexeme("range"));
	structure.push_back(Lexeme("0"));
	structure.push_back(Lexeme("to"));
	structure.push_back(Lexeme("10"));
	structure.push_back(Lexeme(":"));
	structure.push_back(Lexeme("="));
	structure.push_back(Lexeme("32"));
	structure.push_back(Lexeme(";"));
*/

/*TEST STD_LOGIC
	structure.push_back(Lexeme("signal"));
	structure.push_back(Lexeme("a"));
	structure.push_back(Lexeme(","));
	structure.push_back(Lexeme("b"));
	structure.push_back(Lexeme(":"));
	structure.push_back(Lexeme("std_logic"));
	structure.push_back(Lexeme(":"));
	structure.push_back(Lexeme("="));
	structure.push_back(Lexeme("'"));
	structure.push_back(Lexeme("z"));
	structure.push_back(Lexeme("'"));
	structure.push_back(Lexeme(";"));


/*TEST BIT
	structure.push_back(Lexeme("signal"));
	structure.push_back(Lexeme("a"));
	structure.push_back(Lexeme(","));
	structure.push_back(Lexeme("b"));
	structure.push_back(Lexeme(":"));
	structure.push_back(Lexeme("bit"));
	structure.push_back(Lexeme(":"));
	structure.push_back(Lexeme("="));	
	structure.push_back(Lexeme("\'"));
	structure.push_back(Lexeme("0"));
	structure.push_back(Lexeme("\'"));
	structure.push_back(Lexeme(";"));
*/

/*TEST STRING
	structure.push_back(Lexeme("signal"));
	structure.push_back(Lexeme("a"));
	structure.push_back(Lexeme(":"));
	structure.push_back(Lexeme("string"));
	structure.push_back(Lexeme("("));
	structure.push_back(Lexeme("0"));
	structure.push_back(Lexeme("to"));
	structure.push_back(Lexeme("10"));
	structure.push_back(Lexeme(")"));
	structure.push_back(Lexeme(":"));
	structure.push_back(Lexeme("="));	
	structure.push_back(Lexeme("\""));
	structure.push_back(Lexeme("salut"));
	structure.push_back(Lexeme("\""));
	structure.push_back(Lexeme(";"));
*/

/*TEST BOOLEAN
	structure.push_back(Lexeme("signal"));
	structure.push_back(Lexeme("a"));
	structure.push_back(Lexeme(","));
	structure.push_back(Lexeme("b"));
	structure.push_back(Lexeme(":"));
	structure.push_back(Lexeme("boolean"));
	structure.push_back(Lexeme(":"));
	structure.push_back(Lexeme("="));
	structure.push_back(Lexeme("false"));
	structure.push_back(Lexeme(";"));
*/


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

