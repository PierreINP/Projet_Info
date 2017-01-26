/*
This programm is here to perform some functions. It must identify the lexemes, compute them to validate their conformity and then give them a type. 
Input : SourceFile.vhd
Output : Data structure
*/

#include"./../Header/Lexeur.h"
#include"./../Header/Lexeme.h"
#define path_size 100

using namespace std;

int main(int argv, char * argc[])
{
	list<Lexeme> lexeme_list;
	list<Lexeme>::iterator iter;

	;
	char root  [path_size]= "../../../ProjetC/SourceCode/";
	if (argv > 1) {
		strcat(root, argc[1]);
		//Lancement de la routine (ouverture fichier, scan de chaque ligne + découpage)
		lexeme_list = readSource(root);	
	}
	else {
		char fichier [path_size] = "../../../ProjetC/SourceCode/test.vhdl";	
		//Lancement de la routine (ouverture fichier, scan de chaque ligne + découpage)
		lexeme_list = readSource(fichier);
	}

	//Suppression des éléments vides
	lexeme_list = clearList(lexeme_list);
	//Sépare les opérateurs si collés à des ID
	lexeme_list = checkLexeme(lexeme_list);
	

	//Test lecture de la liste de lexeme	
	for(iter = lexeme_list.begin(); iter != lexeme_list.end(); iter ++)
	{
		cout << *iter << endl;
	}
	
}
