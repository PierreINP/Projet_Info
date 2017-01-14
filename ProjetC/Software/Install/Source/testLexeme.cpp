#include "./../Header/Lexeme.h"
#include <iostream>

using namespace std;

int main() {
	
	cout<< "Test 1 : Associate Type" << endl;
	Lexeme Lex1("Entity");
	Lexeme Lex2(";");
	Lex1.associateType();
	Lex2.associateType();
	cout<< "Name " <<Lex1 << "| Type : " <<Lex1.getType() << endl;
	cout<< "Name "<< Lex2 << "| Type : " <<Lex1.getType() << endl;


	cout << endl << "Test 2 : Opérateur = " << endl;

	Lexeme Lex3("Salut");
	cout << "Avant Lexeme = " << Lex3 << endl;
	cout << Lex3 << " = " << Lex1 <<endl;
	Lex3 = Lex1;
	cout << "Après Lexeme =  " << Lex3 << endl;

		
	cout<< "Test 3 : validIdentifier" << endl;

	Lexeme Lex5, Lex6, Lex7, Lex8, Lex9, Lex10;

	Lex5 = "_ident1f1ant";
	Lex6 = "ident1f1ant";
	Lex7 = "_ident1f1ant_";
	Lex8 = "ident1f1ant_";
	Lex9 = "8dent1f1ant_";
	Lex10 = "test_ent";

	cout << Lex5 << Lex5.validIdentifier()<< endl 
<< Lex6 << Lex6.validIdentifier()<< endl 
<< Lex7 << Lex7.validIdentifier()<< endl 
<< Lex8 << Lex8.validIdentifier()<< endl
<< Lex9 << Lex9.validIdentifier()<< endl
<< Lex10 << Lex10.validIdentifier()<< endl;
}
