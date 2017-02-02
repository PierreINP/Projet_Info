#include "./../Header/Lexeme.h"
#include <assert.h>
#include <iostream>

using namespace std;

int main() {
	
	cout << endl << "--------------------------"<< endl << "Test 1 : Associate Type" << endl << "--------------------------" << endl;

	Lexeme Lex1("Entity");
	Lexeme Lex2(";");
	Lexeme Lex3("+");
	Lexeme Lex4("an_id");
/*
	Lex1.associateType();
	Lex2.associateType();
	Lex3.associateType();
	Lex4.associateType();
*/
	cout<< "Name " <<Lex1 << " | Type : " <<Lex1.getType() << endl;
	cout<< "Name "<< Lex2 << " | Type : " <<Lex2.getType() << endl;
	cout<< "Name "<< Lex3 << " | Type : " <<Lex3.getType() << endl;
	cout<< "Name "<< Lex4 << " | Type : " <<Lex4.getType() << endl;

	assert (Lex1.getType()== "keyword");
	assert (Lex2.getType()== "special");
	assert (Lex3.getType()== "operator");
	assert (Lex4.getType()== "id");

	cout << endl << "--------------------------"<< endl << "Test 2 : validIdentifier " << endl << "--------------------------" << endl;

	Lexeme	Lex5("_ident1f1ant");
	Lexeme	Lex6("ident1f1ant");
	Lexeme	Lex7("_ident1f1ant_");
	Lexeme	Lex8("ident1f1ant_");
	Lexeme	Lex9("8dent1f1ant_");/*
	cout << Lex5 <<" "<< Lex5.validIdentifier()<< endl; 
	cout << Lex6 <<" "<< Lex6.validIdentifier()<< endl; 
	cout << Lex7 <<" "<< Lex7.validIdentifier()<< endl; 
	cout << Lex8 <<" "<< Lex8.validIdentifier()<< endl;
	cout << Lex9 <<" "<< Lex9.validIdentifier()<< endl;*/
	assert (Lex5.validIdentifier()== false);
	assert (Lex6.validIdentifier()== true);
	assert (Lex7.validIdentifier()== false);
	assert (Lex8.validIdentifier()== false);
	assert (Lex9.validIdentifier()== false);

	cout << endl << "--------------------------"<< endl << "Test 3 : operator = " << endl <<"--------------------------" << endl;
	
	Lexeme Lex10("Salut");
	cout << "Before operation : Lexeme = " << Lex10 << endl;
	Lex10 = Lex1;
	cout << "After operation : Lexeme = " << Lex10 << endl;
	assert(Lex10.getName() == "entity");

	cout << endl << "--------------------------"<< endl << "Test 3 : operator = " << endl <<"--------------------------" << endl;

	Lexeme Lex11("salut");
	Lexeme Lex12("salut");
	Lex11.associateType();
	Lex12.associateType();

	bool egal = Lex11 == Lex12;
	cout << "Lex11 == Lex12 ?? " << egal << endl;


}
