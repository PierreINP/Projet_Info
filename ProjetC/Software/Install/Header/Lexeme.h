#ifndef _LEXEME_H_
#define _LEXEME_H_

#include <string>
#include <sstream>

using namespace std;


class Lexeme {
private:
	string name;
	string type;
public:
    Lexeme();
    Lexeme(string nameLexeme);  
    Lexeme(char nameLexeme);      	
    ~Lexeme() {}    					

    //Accesseurs
    const string & getName() const;
    string getType() const;

    //Modifieurs
    void setName(const string & nomLexeme);
    void setType(const string & nomType);	

    //Methodes
    void associateType();
    bool validIdentifier();
    //bool Lexeme::checkID(const string & name);
    string toString() const;

    //Fonctions amies
    friend ostream& operator<<(ostream& out, const Lexeme &l);
    friend bool operator==(const Lexeme &a, const Lexeme &b);
    void operator=(const string & b);
};

#endif
