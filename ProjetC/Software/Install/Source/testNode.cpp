#include"./../Header/Lexeur.h"
#include"./../Header/Lexeme.h"
#include "./../Header/Node.h"
#include "./../Header/Node_root.h"

#define path_size 100

using namespace std;

int main(void){

	list<Lexeme> lexeme_list;
	list<Lexeme>::iterator iter; 
	char fichier [path_size]= "../../../ProjetC/SourceCode/test3.vhdl";
	
	lexeme_list = readSource(fichier);//Lancement de la routine (ouverture fichier, scan de chaque ligne + decoupage)
	lexeme_list = clearList(lexeme_list);//Suppression des elements vides
	lexeme_list = checkLexeme(lexeme_list);//Verification de tous les lexemes
	iter = lexeme_list.begin(); //Initialisation sur le 1er lexeme par defaut
 
	Node_root node1(lexeme_list,iter);
	cout << endl << endl << node1;
}
