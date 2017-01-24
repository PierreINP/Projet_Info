/*
This programm is here to perform some functions. It must identify the lexemes, compute them to validate their conformity and then give them a type. 
Input : SourceFile.vhd
Output : Data structure
*/

#include"./../Header/Lexeur.h"
#include"./../Header/Lexeme.h"
#define path_size 100

using namespace std;

int main()
{
	list<Lexeme> lexeme_list;
	list<Lexeme>::iterator iter; 

	
	char fichier [path_size]= "../../../ProjetC/SourceCode/test3.vhdl";
	//Lancement de la routine (ouverture fichier, scan de chaque ligne + découpage)
	lexeme_list = readSource(fichier);
	//Suppression des éléments vides
	lexeme_list = clearList(lexeme_list);
	lexeme_list = checkLexeme(lexeme_list);
	

	//Test lecture de la liste de lexeme	
	for(iter = lexeme_list.begin(); iter != lexeme_list.end(); iter ++)
	{
		//if ((*iter).getName()[0] == 13) {cout << "CHARRIOT" <<endl;}
		//else if (iter->getName()[0] == 0 and iter->getName()[0] <= 32) {cout << "Merde" <<endl;}
		cout << *iter << " | " <<(*iter).getType()<< endl;
	}
	
}
