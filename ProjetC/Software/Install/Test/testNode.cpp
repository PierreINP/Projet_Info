#include"./../Header/Lexeur.h"
#include"./../Header/Lexeme.h"
#include "./../Header/Node.h"
#include "./../Header/Node_root.h"

#define path_size 100

using namespace std;

int main(void){

	vector<Node*> Tree;
	vector<Node*>::iterator it_tree;

	list<Lexeme> lexeme_list;
	list<Lexeme>::iterator iter; 
	char fichier [path_size]= "../../../ProjetC/SourceCode/test3.vhdl";
	
	lexeme_list = readSource(fichier);  //Lancement de la routine (ouverture fichier, scan de chaque ligne + decoupage)
	lexeme_list = clearList(lexeme_list);//Suppression des elements vides
	lexeme_list = checkLexeme(lexeme_list);//Verification de tous les lexemes
	iter = lexeme_list.begin();         //Initialisation sur le 1er lexeme par defaut

	Node_root source(lexeme_list,iter); // create an instance root of node which is the highest level of nodes
	Tree = source.getSons();	    // get all root sons
	cout << endl << source << endl;	    // display root structure which contains all lexemes

	////////////* Display all root sons lexemes structures *///////
	for (it_tree = Tree.begin(); it_tree != Tree.end(); it_tree++){
		cout << endl << (**it_tree).displayStruct() << endl;
	}
}

	/*DEBUG : DON'T FORGET TO DELETE
	for(iter = lexeme_list.begin(); iter != lexeme_list.end(); iter ++)
	{
		cout << *iter << endl;
	}*/
