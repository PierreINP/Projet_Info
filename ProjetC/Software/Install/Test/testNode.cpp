#include"./../Header/Lexeur.h"
#include"./../Header/Lexeme.h"
#include "./../Header/Node.h"
#include "./../Header/Node_root.h"

#define path_size 100

using namespace std;

int main(void){

	list<Lexeme> lexeme_list;
	list<Lexeme>::iterator iter = lexeme_list.begin(); //Initialisation sur le 1er lexeme par defaut
	char fichier [path_size]= "../../../ProjetC/SourceCode/test3.vhdl";
	
	lexeme_list = readSource(fichier);//Lancement de la routine (ouverture fichier, scan de chaque ligne + decoupage)
	lexeme_list = clearList(lexeme_list);//Suppression des elements vides
	lexeme_list = checkLexeme(lexeme_list);//Verification de tous les lexemes
 
	Node_root node1(lexeme_list,iter);

	cout << endl << node1;
	//cout << (*node1.getLexIt())<< endl; //display lexeme name linked to node1 iterator
	//cout << (*node1.getLexIt()).getType()<< endl; //display lexeme type linked to node1 iterator
	cout << node1.displayStruct()<< endl;	
}
