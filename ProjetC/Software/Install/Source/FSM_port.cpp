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
	structure.push_back(Lexeme("port"));
	structure.push_back(Lexeme("("));

	structure.push_back(Lexeme("a"));
	structure.push_back(Lexeme(","));
	structure.push_back(Lexeme("b"));
	structure.push_back(Lexeme(":"));
	structure.push_back(Lexeme("out"));
	structure.push_back(Lexeme("std_logic"));
	structure.push_back(Lexeme(";"));

	structure.push_back(Lexeme("cin"));
	structure.push_back(Lexeme(":"));
	structure.push_back(Lexeme("in"));
	structure.push_back(Lexeme("bit"));

	structure.push_back(Lexeme(")"));
	structure.push_back(Lexeme(";"));

	
	list<Lexeme>::iterator it;
	list<Lexeme>::iterator it_tmp;

		int step = 0;
		bool countWay;
		string tmpBound;
		

		cout << "							Start PORT structure validation"<< endl;
		for(it = structure.begin(); it != structure.end(); it ++){
			it_tmp = it;
			//cout << step << " | " << *it <<endl;

			switch(step){		
				case 0:		if((*it).getName()=="port")	{step++;}
						else 				{step=-1;} //go to default case 
						break;

				case 1:		if((*it).getName()=="(")	{step++;}
						else {
							step=-1;
							cout << "Manque la ( après port!" << endl;
						}
						break;

				
				//Case 2 et 3 retrieve IDs before ':' lexeme 
				case 2 :   	if((*it).getType()=="id"){
							names.push_back((*it).getName());
							if((*++it_tmp).getName() == ",")	{step++;}
							else if((*++it_tmp).getName() != ":")	{step=4;}
							else {
							step=-1;
							cout << "Les ports doivent être des identifiants valides !" << endl;
						}
						}
						break;

				case 3 :        //Go back to case 2 if ID after "," 
						if((*++it_tmp).getType()=="id") 	{step--;}
						else 					{step=-1;}
						break;

				case 4 :     	if((*it).getName()==":")		{step++;}
						else 					{step=-1;}
						break;

				case 5 :       if((*it).getName()== "in"){		step++;
							direction = "in"; 
						}
						else if((*it).getName()== "out"){	
							direction = "out";
							step++;
						}
						else {
							step=-1;
							cout << "Mauvaise direction pour un port!" << endl;
						}
						break;

				//Détermination du type du port
				case 6 :        if((*it).getName()== "bit"){
							type = "bit";
							step++;
						}
						else if((*it).getName()== "std_logic"){
							type = "std_logic";
							step++;
						}
						else if((*it).getName()== "bit_vector"){
							type = "bit_vector";
							step = 10;
						}
						else if((*it).getName()== "std_logic_vector"){
							type = "std_logic_vector";
							step = 10;
						}
						else {
							step=-1;
							cout << "Type du port non reconnu!" << endl;
						}
						break;

				//Type scalaire || fin d'un port --> fin de PORT ?
				case 7 :        cout <<"		>>> Create Port son : portScalaire"<< endl;
						createScalaire(names,direction,type); //end of line : creation of scalaire port
						names.clear();
						direction.clear();
						type.clear();
						if((*it).getName()==";"  and (*++it_tmp).getName() == ")"){step = 8;} // si ")" après un port --> fin de PORT
						else if((*it).getName()==";"  or (*++it_tmp).getType() == "id"){step = 2;} // si "id" après un port --> nouveau port
						else {
							step=-1;
							cout << "fini un ligne dans port par ;!" << endl;
						}
						break;
		
				//Type composite
		
				case 10 :       if((*it).getName()=="range"){step = 16;} 
						else if((*it).getName() == "("){step++;}
						else {
							step=-1;
							cout << "range est à utilser pour le type de port écrit !" << endl;
						}
						break;

				//Avec up/down to
				case 11 :       if(isEntier((*it).getName())){
							lowerBound = (*it).getName();
							step++;
						}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 12 :       if((*it).getName()== "upto"){
							countWay = true;
							step++;
						}
						else if((*it).getName()== "downto"){
							countWay = false;
							step++;
						}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 13 :       if(isEntier((*it).getName())){
							upperBound = (*it).getName();
							step++;
						}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 14 :       if((*it).getName() == ")"){step++;}
						else {
							step=-1;
							cout << "parenthèse fermante après un port composite !" << endl;
						}
						break;
					
				case 15 :       if (!countWay){ //if range is downto type ; exchange upper and lower Bounds
							tmpBound=lowerBound; 
							lowerBound = upperBound;
							upperBound = tmpBound;
						}
						cout <<"		>>> Create Port son : portComposite"<< endl;
						createComposite(names,direction,type,lowerBound,upperBound);//end of line : creation of composite port
						names.clear();
						direction.clear();
						type.clear();
						lowerBound.clear();
						upperBound.clear();
						if((*it).getName()== ")"){step = 9;}
						else if((*it).getName() == ";" and (*++it_tmp).getType() == "id"){step = 2;}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;
		
				//Avec range
				case 16 :       if(isEntier((*it).getName())){
							lowerBound = (*it).getName();
							step++;
						}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 17 :       if((*it).getName()== "to"){
							step++;
						}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 18 :       if(isEntier((*it).getName())){
							upperBound = (*it).getName();
							step=15;
						}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				//FIN DE FSM
				case 8 :        if((*it).getName()==")"){step++;}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 9 :        if((*it).getName()==";"){
							cout << "							Structure PORT OK" << endl;
							return true;
						}
						else return false;    
				

				default :	cout << "							error" << endl; //cf gestion d'erreur
						return false;		  
			}
		}
}

