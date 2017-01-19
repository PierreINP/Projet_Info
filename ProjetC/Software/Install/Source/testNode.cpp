#include "./../Header/Node.h"
#include <iostream>

using namespace std;

int main(void){

   Lexeme Lex1("Entity");
   Lexeme Lex2("Architecture");
   Node pere("Root");
   cout << Lex1.getType()<< endl;
   cout << Lex2.getType()<< endl;
   cout << pere.getLabel()<< endl << endl;
   pere.addSon(pere.createSon(Lex1));
   pere.addSon(pere.createSon(Lex1));
   pere.addSon(pere.createSon(Lex2));
   pere.getSons();
   cout << endl;
}
