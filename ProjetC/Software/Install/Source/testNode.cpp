#include "./../Header/Node.h"
#include "./../Header/Node_root.h"
#include "./../Header/Node_entity.h"

#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(void){
   Node_root node1;
   Node_entity node2;

   cout << node1.getLabel()<<endl;
   cout<<node2.getLabel()<<endl;
   
   node1.createSons();
   cout << node1;


//---------->Tests à réaliser après validation de la structure objet<---------
/* 
   Node_root pere();
   cout << pere.getLabel()<< endl;

   list<Lexeme> Structure; // Simule la structure user lue depuis le source VHDL
   Lexeme Lex1("Entity");
   Lexeme Lex2("full_add1");
   Lexeme Lex3("is");
  
   Structure.push_back(Lex1);
   Structure.push_back(Lex2);
   Structure.push_back(Lex3);

   list<Lexeme>::iterator it;

   for (it = Structure.begin(); it != Structure.end(); it++){		//parcours de tous les lexemes du fichier source
		if (it.getName() == "entity"){				//a terme : switch avec tous les lexemes speciaux
			pere.enfants.push_back(new Node_entity());	//Necessite que l'attribut enfants soit public
		}
	}
*/
}

