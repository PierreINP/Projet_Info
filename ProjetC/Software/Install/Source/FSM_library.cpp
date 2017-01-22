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

	structure.push_back(Lexeme("library"));
	structure.push_back(Lexeme("ieee"));
	structure.push_back(Lexeme(";"));
	structure.push_back(Lexeme("use"));

	
	list<Lexeme>::iterator it;
	list<Lexeme>::iterator it_tmp;
	int step = 0;

	string library_name;

	for(it = structure.begin(); it != structure.end(); it ++)
	{
		it_tmp = it;
		cout << step << " | " << *it <<endl;
///////////////////////////////////////////CHECKSTRUCTURE LIBRARY///////////////////////////////////////////
		switch(step){		
			case 0:		if((*it).getName()=="library"){step++;}
					else step=-1;	//rentre dans le cas default
					break;

			case 1:		if((*it).getType()=="id"){
						library_name = (*it).getName();
						step++;
					}
					else step=-1;	
					break;

			case 2:		if((*it).getName()==";"){step++;}
					else if((*++it_tmp).getName()=="library"){step = 0;}
					else step=-1;	
					break;

			case 3 :        if((*it).getName()=="use"){cout << "Structure LIBRARY validée" << endl; return true;}
					else {return false;} 

			default :	cout << "error" << endl; //cf gestion d'erreur
					return false;		  
		}

	}
}
