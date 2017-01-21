#ifndef NODE_H
#define NODE_H

#include "./../Header/Lexeme.h"

#include <vector>
#include <list>
#include <string>

using namespace std;

class Node {
private:
	string label;
	list<Lexeme> structure;
	vector <Node*> enfants;
public:
	Node(string l);
	virtual ~Node();

//methods
	//Node* createSon(Lexeme special);
	//void addSon(Node* enfant);
	//void addSon();
	//void delSon(Node* enfant);
	//void getSons();
	
	virtual bool checkStruct() = 0; // pure virtual
//Remarque : renvoyer le numero de l'iterateur avec le fils courant

	//Node createSon(Lexeme lex);
	//void addSon(Node enfant);
	//void getSons();


//accessors
	const string & getLabel()const;
	const list<Lexeme> & getStructure() const;
};

#endif 
