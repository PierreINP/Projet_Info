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

bool isStd_Logic(char a) {
//Vérifie si chaque caractère d'un lexeme est un type reconnu de std logic
	char tab_type[10] = {"ux01zwlh-"};
	int i;
	for (i=0; i <9; i++) {
		//cout << "LEX " << a[0] << " TYPE? " << tab_type[i] <<endl;
		if(a == tab_type[i]){
			return true;
		}
	}
return false;
}

int main() {

	list<Lexeme> structure;
//List for port test
	structure.push_back(Lexeme("type"));
	structure.push_back(Lexeme("pouet_pouet"));
/*
	structure.push_back(Lexeme("is"));
	structure.push_back(Lexeme("("));
	structure.push_back(Lexeme("bleu"));
	structure.push_back(Lexeme(","));
	structure.push_back(Lexeme("rouge"));
	structure.push_back(Lexeme(","));
	structure.push_back(Lexeme("tamere"));
	structure.push_back(Lexeme(")"));
	structure.push_back(Lexeme(";"));*/


/*
	structure.push_back(Lexeme("is"));
	structure.push_back(Lexeme("("));
	structure.push_back(Lexeme("'"));
	structure.push_back(Lexeme("x"));
	structure.push_back(Lexeme("'"));
	structure.push_back(Lexeme(","));	
	structure.push_back(Lexeme("'"));
	structure.push_back(Lexeme("0"));
	structure.push_back(Lexeme("'"));
	structure.push_back(Lexeme(")"));
	structure.push_back(Lexeme(";"));*/

	structure.push_back(Lexeme("is"));
	structure.push_back(Lexeme("array"));
	structure.push_back(Lexeme("("));
	structure.push_back(Lexeme("0"));
	structure.push_back(Lexeme("to"));
	structure.push_back(Lexeme("31"));
	structure.push_back(Lexeme(")"));
	structure.push_back(Lexeme("of"));
	structure.push_back(Lexeme("bit"));
	structure.push_back(Lexeme(";"));


	list<Lexeme>::iterator it;
	list<Lexeme>::iterator it_tmp;
	int step = 0;


		for(it = structure.begin(); it != structure.end(); it ++)
	{
		it_tmp = it;
		cout << step << " | " << *it <<endl;

///////////////////////////////////////////CHECKSTRUCTURE PORT///////////////////////////////////////////
		switch(step){		
			case 0:		if((*it).getName()=="type"){step++;}
					else step=-1;	//rentre dans le cas default
			
					break;

			case 1:		if((*it).getType()=="id"){step++;}
					else step=-1;
					break;


			case 2 :     	if((*it).getName()=="is"){step++;}
					else step=-1;
					break;
			

			case 3 :        if((*it).getName()== "("){
						//déclaration de type
						if ((*++it_tmp).getType() == "id") {step++;} //type énuméré par strings
						else {step = 8;} //type énuméré avec valeurs num
					}
					else if((*it).getName()== "array"){
						//tableau d'un type deja connu
						step = 12;
					}
					else step=-1;
					break;
	
			
			//type énuméré par strings	
						//Case 6 et 7 parcourt les Id avant le ")"
			case 4 :   	if((*it).getType()=="id"  and (*++it_tmp).getName() == ","){
						//recuperer ID dans un port
						step++;
					}
					else if((*it).getType()=="id"  or (*++it_tmp).getName() == ")"){
						//recuperer ID dans un port
						step = 6;
					}
					else step=-1;
					break;

			case 5 :        //Si id après "," on repart en 6. 
					if((*++it_tmp).getType()=="id") {step--;}
					else step=-1;
					break;

			case 6 : 	if((*it).getName()==")") {step++;}
					else step=-1;
					break;
	
			
			//type énuméré avec valeurs num
			//Seule gestion des types par valeurs num d'un caractere : bit ou std_logic entre ' '
			case 8 : 	if((*it).getName()=="'") {step++;}
					else step=-1;
					break;

			case 9 : 	if(isStd_Logic((*it).getName()[0])) {
						//Valeur du type 0, 1 ou std_logic
						step++;
					}
					else step=-1;
					break;

			case 10 : 	if((*it).getName()=="'") {step++;}
					else step=-1;
					break;


			case 11 : 	if((*it).getName() == ")"){
						step=7; //Fin de type
					}
					else {step = 8;} //Nouvelle valeur à prendre en compte
					break;

			//tableau d'un type deja connu
			case 12 : 	if((*it).getName()=="(") {step++;}
					else step=-1;
					break;

			case 13 : 	if(isEntier((*it).getName())) {
						//Recuperation de l'entier
						step++;
					}
					else step=-1;
					break;

			case 14 : 	if((*it).getName()== "to" ) {step++;}
					else step=-1;
					break;

			case 15 : 	if(isEntier((*it).getName())) {
						//Recuperation de l'entier
						step++;
					}
					else step=-1;
					break;

			case 16 : 	if((*it).getName()== ")" ) {step++;}
					else step=-1;
					break;

			case 17 : 	if((*it).getName()== "of" ) {step++;}
					else step=-1;
					break;

			case 18 : 	if((*it).getType()== "id" ) {
						//recuperer le type utilisé
						step = 7;
					}
					else step=-1;
					break;

			//FIN DE FSM
			case 7 :        if((*it).getName()==";"){cout << "Structure TYPE validée" << endl; return true;}
					else {return false;}    
					

			default :	cout << "error" << endl; //cf gestion d'erreur
					return false;		  
		}
	}
}

