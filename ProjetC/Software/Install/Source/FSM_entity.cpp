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

	structure.push_back(Lexeme("entity"));
	structure.push_back(Lexeme("toto"));
	structure.push_back(Lexeme("is"));
	structure.push_back(Lexeme("port"));	
	structure.push_back(Lexeme("end"));
	structure.push_back(Lexeme("toto"));
	structure.push_back(Lexeme(";"));

	
	list<Lexeme>::iterator it;
	list<Lexeme>::iterator it_tmp;
	int step = 0;
	string entity_ID;


		for(it = structure.begin(); it != structure.end(); it ++)
	{
		it_tmp = it;
		cout << step << " | " << *it <<endl;
///////////////////////////////////////////CHECKSTRUCTURE ENTITY///////////////////////////////////////////
		switch(step){		//FSM struct entity
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
		}

	}
}

