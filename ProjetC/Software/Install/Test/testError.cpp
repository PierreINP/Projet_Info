#include "./../Header/Error.h"
#include "./../Header/Lexeme.h"


int main() {

Lexeme Lex1 ("entity");
Error erreur;

erreur.generateLog("I01");
erreur.generateLog("E02");
erreur.generateLog("E04");
erreur.generateLog("A05");

//cout << erreur;
};
