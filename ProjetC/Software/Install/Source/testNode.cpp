#include "./../Header/Node.h"
//#include "./../Header/Node_entity.h"
#include <iostream>

using namespace std;

int main(void){

   Lexeme Lex1("Entity");
   Lexeme Lex2("Architecture");
   Node_entity pere();
   cout << pere.getLabel()<< endl;
   pere.addSon(pere.createSon(Lex1));
   pere.addSon(pere.createSon(Lex1));
   pere.addSon(pere.createSon(Lex2));
   pere.getSons();
   cout << endl;
}
