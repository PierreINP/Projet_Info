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
	std::list<Lexeme> lexeme_list;
	list<Lexeme>::iterator iter; 

	//char fichier [path_size]= "/users/phelma/phelma2015/lamypi/ProjetC/SourceCode/test.vhdl";
	char fichier [path_size]= "../../../ProjetC/SourceCode/test.vhdl";
	lexeme_list = readSource(fichier);

	//Test lecture lexeme dans liste
		
	for(iter = lexeme_list.begin(); iter != lexeme_list.end(); iter ++)
	{
		cout << *iter << endl;
	}	
}
