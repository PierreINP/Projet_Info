#include "./../Header/Lexeme.h"
#include <assert.h>
#include <iostream>

using namespace std;

int main() {
	
	cout << endl << "--------------------------"<< endl << "Test 1 : Associate Type" << endl << "--------------------------" << endl;
	Lexeme Lex1("Entity");
	Lexeme Lex2(";");
<<<<<<< HEAD
	Lexeme Lex3("+");
	Lexeme Lex4("an_id");
	Lex1.associateType();
	Lex2.associateType();
	Lex3.associateType();
	Lex4.associateType();
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
	Lexeme	Lex9("8dent1f1ant_");
	cout << Lex5 <<" "<< Lex5.validIdentifier()<< endl; 
	cout << Lex6 <<" "<< Lex6.validIdentifier()<< endl; 
	cout << Lex7 <<" "<< Lex7.validIdentifier()<< endl; 
	cout << Lex8 <<" "<< Lex8.validIdentifier()<< endl;
	cout << Lex9 <<" "<< Lex9.validIdentifier()<< endl;
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
=======
	Lexeme Lex5, Lex6, Lex7, Lex8, Lex9, Lex10;


	Lex5 = "_ident1f1ant";
	Lex6 = "ident1f1ant";
	Lex7 = "_ident1f1ant_";
	Lex8 = "ident1f1ant_";
	Lex9 = "8dent1f1ant_";
	Lex10 = "test_ent";

	/*Lex1.associateType();
	Lex2.associateType();
	Lex10.associateType();*/
	cout<< "Name " <<Lex1 << "| Type : " <<Lex1.getType() << endl;
	cout<< "Name "<< Lex2 << "| Type : " <<Lex2.getType() << endl;
	cout<< "Name "<< Lex10 << "| Type : " <<Lex10.getType() << endl;


	cout << endl << "Test 2 : Opérateur = " << endl;

	Lexeme Lex3("Salut");
	cout << "Avant Lexeme = " << Lex3 << endl;
	cout << Lex3 << " = " << Lex1 <<endl;
	Lex3 = Lex1;
	cout << "Après Lexeme =  " << Lex3 << endl;

		
	cout<< "Test 3 : validIdentifier" << endl;

	cout << Lex5 << Lex5.validIdentifier()<< endl 
<< Lex6 << Lex6.validIdentifier()<< endl 
<< Lex7 << Lex7.validIdentifier()<< endl 
<< Lex8 << Lex8.validIdentifier()<< endl
<< Lex9 << Lex9.validIdentifier()<< endl
<< Lex10 << Lex10.validIdentifier()<< endl;
>>>>>>> c69983e5d0f73f2d023685b0cdfa7e4a1d92e1ee
}
