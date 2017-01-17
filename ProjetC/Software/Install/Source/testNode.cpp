#include "./../Header/Node.h"
#include <iostream>

using namespace std;

int main(void){

   Lexeme Lex1("Entity");
   Node pere("Root");
   cout << Lex1.getType()<< endl;
   cout << pere.getLabel()<< endl;
   pere.addSon(pere.createSon(Lex1));
   pere.getSons();
   cout << endl;
}
