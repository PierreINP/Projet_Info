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

	structure.push_back(Lexeme("process"));
	structure.push_back(Lexeme("("));
	structure.push_back(Lexeme("sal_ut"));
	structure.push_back(Lexeme(","));
	structure.push_back(Lexeme("conio"));
	structure.push_back(Lexeme(")"));
	structure.push_back(Lexeme("begin"));/*
	structure.push_back(Lexeme("if"));	
	structure.push_back(Lexeme("case"));
	structure.push_back(Lexeme("declaration"));	
	structure.push_back(Lexeme("if"));
	structure.push_back(Lexeme("assignation"));*/
	structure.push_back(Lexeme("end"));
	structure.push_back(Lexeme("process"));
	structure.push_back(Lexeme(";"));

	
	list<Lexeme>::iterator it;
	list<Lexeme>::iterator it_tmp;
	int step = 0;

	string library_name;

	for(it = structure.begin(); it != structure.end(); it ++)
	{
		it_tmp = it;
		cout << step << " | " << *it <<endl;
///////////////////////////////////////////CHECKSTRUCTURE PROCESS///////////////////////////////////////////
		switch(step){		
			case 0:		if((*it).getName()=="process"){step++;}
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
					else if((*it).getType()=="id"  or (*++it_tmp).getName() == ")"){
						//recuperer ID dans un port
						step = 4;
					}
					else step=-1;
					break;

			case 3 :        //Si id après "," on repart en 2. 
					if((*++it_tmp).getType()=="id") {step--;}
					else step=-1;
					break;
	

			case 4 :     	if((*it).getName()==")"){step++;}
					else step=-1;
					break;

			case 5 :     	if((*it).getName()=="begin"){
						if ((*++it_tmp).getName() == "end") step++;
						else if ((*++it_tmp).getName() != "end") step = 9;
					}
					else step=-1;
					break;

			case 9 :     	if((*it).getName()=="declaration" or (*it).getName()=="if" or (*it).getName()=="assignation" or (*it).getName()=="case"){step = 9;}
					else if((*it).getName()=="end") {
						step = 7; 
					}
					else step=-1;
					break;

			case 6 :     	if((*it).getName()=="end"){step++;}
					else step=-1;
					break;

			case 7 :     	if((*it).getName()=="process"){step++;}
					else step=-1;
					break;

			case 8 :     	if((*it).getName()==";"){
						cout << "Structure PROCESS validée" << endl; 
						return true;
					}
					else step=-1;
					break;

			default :	cout << "error" << endl; //cf gestion d'erreur
					return false;		  
		}

	}
cout << "Structure DECLERATION validée" << endl; 
return true;
}
