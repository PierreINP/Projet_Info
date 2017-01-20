#ifndef NODE_H
#define NODE_H

#include "./../Header/Lexeme.h"
//#include "./../Header/Node_entity.h"

#include <vector>
#include <list>
#include <string>

using namespace std;

class Node {
private:
	list<Lexeme> structure;
	vector <Node*> enfants;
public:
	Node();
	virtual ~Node();

//methods
<<<<<<< HEAD
	//Node* createSon(Lexeme special);
	//void addSon(Node* enfant);
	void addSon();
	//void delSon(Node* enfant);
	void getSons();
	
	virtual bool checkStruct() = 0; // pure virtual
//Remarque : renvoyer le numero de l'iterateur avec le fils courant
=======
	Node createSon(Lexeme lex);
	void addSon(Node enfant);
	void getSons();
>>>>>>> 772586236dcbc5a8ea90eb35766964e29e628ffe

//accessors
	const string & getLabel()const;
	const list<Lexeme> & getStructure() const;
};

#endif 
