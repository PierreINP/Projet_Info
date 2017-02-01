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


int main() {

	list<Lexeme> structure;
	
//List for entity test

	structure.push_back(Lexeme("architecture"));
	structure.push_back(Lexeme("arc1"));
	structure.push_back(Lexeme("of"));
	structure.push_back(Lexeme("compteurDownUp"));	
	structure.push_back(Lexeme("is"));
	structure.push_back(Lexeme("declaration"));
	structure.push_back(Lexeme("begin"));
	structure.push_back(Lexeme("if"));
	structure.push_back(Lexeme("if"));
	structure.push_back(Lexeme("process"));	
	structure.push_back(Lexeme("end"));
	structure.push_back(Lexeme("arc1;"));	
	structure.push_back(Lexeme(";"));

	
	list<Lexeme>::iterator it;
	list<Lexeme>::iterator it_tmp;
	int step = 0;

	for(it = structure.begin(); it != structure.end(); it ++)
	{
		it_tmp = it;
		cout << step << " | " << *it <<endl;
///////////////////////////////////////////CHECKSTRUCTURE ARCHITECTURE///////////////////////////////////////////
		switch(step){		
			case 0:		if((*it).getName()=="architecture"){step++;}
					else step=-1;	//rentre dans le cas default
					break;

			case 1:		if((*it).getType()== "id" ){
						/*architecture ID*/
						step++;
					}
					else step=-1;
					break;

			case 2:		if((*it).getName()=="of"){step++;}
					else step=-1;
					break;

			case 3:		if((*it).getType()== "id" ){
						/*library ID*/
						step++;
					}
					else step=-1;
					break;

			case 4:		if((*it).getName()=="is" and (*++it_tmp).getName()=="begin"){step++;}
					else if((*it).getName()=="is" or (*++it_tmp).getName()=="declaration"){step = 9;}
					else step=-1;
					break;

			case 5:		if((*it).getName()=="begin" and (*++it_tmp).getName()!="end"){step = 9;}//ca va en step 10
					if((*it).getName()=="begin" or (*++it_tmp).getName()=="end"){step++;}
					else step=-1;
					break;
					
			case 9:		if((*it).getName()=="declaration"){step = 5;}
					else step=-1;
					break;

			case 10:	if((*it).getName()!="end"){
						//On passse les blocs dans le process Assig, Proccess, If, Case ...
					}
					else if((*it).getName()=="end"){step = 7;}
					else step=-1;
					break;

			///////////////////FIN DE FSM///////////////////
			case 6:		if((*it).getName()=="end"){step++;}
					else step=-1;
					break;

			case 7:		if((*it).getType()== "id" ){
						/*architecture ID ??*/
						step++;
					}
					else step=-1;
					break;

			case 8 :        if((*it).getName()==";"){cout << "Structure ARCHITECTURE validée" << endl; return true;}
					else {return false;}    

			default :	cout << "error" << endl; //cf gestion d'erreur
					return false;		  
		}

	}
}
