#include"./../Header/Lexeur.h"
#include"./../Header/Lexeme.h"
#include "./../Header/Node.h"
#include "./../Header/Node_root.h"

#define path_size 100

using namespace std;

int main(int argv, char * argc[]){

	vector<Node*> TreeLvl1;
	vector<Node*> TreeLvl2;
	vector<Node*> TreeLvl3;
	vector<Node*> TreeLvl4;
	vector<Node*>::iterator it_tree_lvl1;
	vector<Node*>::iterator it_tree_lvl2;
	vector<Node*>::iterator it_tree_lvl3;
	vector<Node*>::iterator it_tree_lvl4;

	//vector<Node*> Entity_sons;
	//vector<Node*> Port_sons;
	
	//vector<Node*>::iterator it_entity_sons;
	//vector<Node*>::iterator it_port_sons;

	list<Lexeme> lexeme_list;
	list<Lexeme>::iterator iter; 

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
	
	//lexeme_list = readSource(fichier);  //Lancement de la routine (ouverture fichier, scan de chaque ligne + decoupage)
	lexeme_list = clearList(lexeme_list);//Suppression des elements vides
	lexeme_list = checkLexeme(lexeme_list);//Verification de tous les lexemes
	iter = lexeme_list.begin();         //Initialisation sur le 1er lexeme par defaut

	Node_root source(lexeme_list,iter); // create an instance root of node which is the highest level of nodes
	TreeLvl1 = source.getSons();	    // get all root sons
	cout << endl << source << endl;	    // display root structure which contains all lexemes

	////////////* Display all root sons lexemes structures *///////
	for (it_tree_lvl1 = TreeLvl1.begin(); it_tree_lvl1 != TreeLvl1.end(); it_tree_lvl1++){
		cout << endl << **it_tree_lvl1<< endl;//display sons & structure
		TreeLvl2 = (**it_tree_lvl1).getSons();

		for (it_tree_lvl2 = TreeLvl2.begin(); it_tree_lvl2 != TreeLvl2.end(); it_tree_lvl2++){
			cout << endl << **it_tree_lvl2<< endl;//display sons & structure
			TreeLvl3 = (**it_tree_lvl2).getSons();
		
			for (it_tree_lvl3 = TreeLvl3.begin(); it_tree_lvl3 != TreeLvl3.end(); it_tree_lvl3++){
				cout << endl << **it_tree_lvl3<< endl;//display sons & structure
				TreeLvl4 = (**it_tree_lvl3).getSons();

				for (it_tree_lvl4=TreeLvl4.begin(); it_tree_lvl4 != TreeLvl4.end(); it_tree_lvl4++){
					cout << endl << **it_tree_lvl4<< endl;//display sons & structure
				}
			}
		}
	}	
}
