#include"./../Header/Lexeur.h"
#include"./../Header/Lexeme.h"
#include "./../Header/Node.h"
#include "./../Header/Node_root.h"

#define path_size 100

using namespace std;

int main(void){

	vector<Node*> Tree;
	vector<Node*> Entity_sons;
	vector<Node*> Port_sons;
	vector<Node*>::iterator it_tree;
	vector<Node*>::iterator it_entity_sons;
	vector<Node*>::iterator it_port_sons;

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
		cout << endl << **it_tree << endl;//display sons & structure
		if ((**it_tree).getLabel()=="Entity"){
			Entity_sons = (**it_tree).getSons();
		}
	}
	for(it_entity_sons = Entity_sons.begin();it_entity_sons != Entity_sons.end(); it_entity_sons++){
		if ((**it_entity_sons).getLabel()==  "Port"){
			cout << **it_entity_sons << endl;
			Port_sons = (**it_entity_sons).getSons();
		}
	}
	for(it_port_sons = Port_sons.begin();it_port_sons != Port_sons.end(); it_port_sons++){
		cout << (**it_port_sons).getLabel() << " || " <<(**it_port_sons).getName() << " || "<< (**it_port_sons).getDirection() << " || "<< (**it_port_sons).getType() <<" || "<< (**it_port_sons).getLowerBound() <<" || "<< (**it_port_sons).getUpperBound() << endl;
	}		
}
