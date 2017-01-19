#include "./../Header/Error.h"
#include "./../Header/Lexeme.h"


int main() {

Lexeme Lex1 ("entity");
Error erreur;

erreur.generateLog("01", 3, Lex1.getName());

erreur.display();

//cout << erreur;
};
