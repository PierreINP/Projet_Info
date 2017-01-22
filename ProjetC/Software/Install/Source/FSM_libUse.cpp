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

	structure.push_back(Lexeme("use"));
	structure.push_back(Lexeme("lib_name"));
	structure.push_back(Lexeme("."));
	structure.push_back(Lexeme("package"));	
	structure.push_back(Lexeme(";"));

	
	list<Lexeme>::iterator it;
	list<Lexeme>::iterator it_tmp;
	int step = 0;
	
	string library_name; //A récuperer depuis library pour vérfier contexte
	string package_name;

	for(it = structure.begin(); it != structure.end(); it ++)
	{
		it_tmp = it;
		cout << step << " | " << *it <<endl;
///////////////////////////////////////////CHECKSTRUCTURE LIBRARY USE///////////////////////////////////////////
		switch(step){		
			case 0:		if((*it).getName()=="use"){step++;}
					else step=-1;	//rentre dans le cas default
					break;

			case 1:		if((*it).getType()== "id" ){
						/* if(library_name == (*it).getName()){}
						else step=-1;*/
						step++;
					}
					else step=-1;
					break;

			case 2:		if((*it).getName()=="."){step++;}
					else step=-1;
					break;

			case 3:		if((*it).getType()== "id"){
						//package_name == (*it).getName();
						step++;
					}
					else step=-1;
					break;

			case 4 :        if((*it).getName()==";"){cout << "Structure LIBRARY USE validée" << endl; return true;}
					else {return false;}    
					

			default :	cout << "error" << endl; //cf gestion d'erreur
					return false;		  
		}

	}
}
