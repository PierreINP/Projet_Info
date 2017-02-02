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

	structure.push_back(Lexeme("signal"));
	structure.push_back(Lexeme("type"));
	structure.push_back(Lexeme("type"));
	structure.push_back(Lexeme("varable"));
	structure.push_back(Lexeme("component"));
	structure.push_back(Lexeme("variable"));

	
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
			case 0:		if((*it).getName()=="signal" or (*it).getName()=="variable" or (*it).getName()=="component" or (*it).getName()=="type"){step = 0;}

					else {
						cout << "error" << endl; //cf gestion d'erreur
						return false;	//rentre dans le cas default
					}
					break;

			default :	cout << "error" << endl; //cf gestion d'erreur
					return false;		  
		}

	}
cout << "Structure DECLARATION validée" << endl; 
return true;
}
