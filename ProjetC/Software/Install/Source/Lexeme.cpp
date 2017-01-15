#include "./../Header/Lexeme.h"
#include <iostream>

#define N 50

using namespace std;
 
extern string keywordList[];
extern char specialList[];
extern string operatorList[];
    
    Lexeme::Lexeme():name("") {}

    Lexeme::Lexeme(string nameLexeme){
	int i;
	// Minimaze every character of the lexeme string, to have a standard base for futur computing
	for(int i = 0; nameLexeme[i] != '\0'; i++){
        	if (nameLexeme[i]  >= 65 &&  nameLexeme[i] <= 90){
			nameLexeme[i] = nameLexeme[i] + 32; // 32 is the offset between Maj and Miin in ASCII table
		}
	}
	name = nameLexeme;
	type = "id";
	associateType();
    }
    
       Lexeme::Lexeme(char nameLexeme){
	name = nameLexeme;
	type = "special";
    }

    //Accesseurs
    const string & Lexeme::getName() const{
        return name;
    }

    string Lexeme::getType() const{
        return type;
    }

    //Modifieurs
    void Lexeme::setName(const string & nomLexeme){
    	name = nomLexeme;
    }	
	
    void Lexeme::setType(const string & nomType){
    	type = nomType;
    }	

    //Methodes

    void Lexeme::associateType(){
	/*
	IN : lexeme
	OUT : lexeme's type
	It searchs on special/keyword/operator list contained in syntaxConstrains.cpp to define type
	*/
	type = "id";
	setType("id");			
	for(int i = 0; i < N ; i++){	
		if(name == keywordList[i]){ 
			type = "keyword";
			setType("keyword");
			break;
		}
		else if (name[0] == specialList[i]){ 
			type = "special";
			setType("special");
			break;
		}
		else if (name == operatorList[i]){
			type = "operator";
			setType("operator");
			break;
		}
	}	
    }

    bool Lexeme::validIdentifier() {
	/*
	IN : lexeme identifier
	OUT : bool if lexeme fit to rules 
	Rules :
		1/ No "_" at beginning or end
		2/ No 0-9 at beginning
		3/ between, juste have alphanum or "_"
	*/
	int len = this->getName().size();
	string id = getName();
	
	int i;
	// No "_" at beginning or end
	if (id[0] == 95) {return false;}
	else if (id[len-1] == 95) {return false;}
	// No 0-9 at beginning
	else if (id[0]  >= 48 && id[0] <= 57 ){return false;}

	// between, juste have alphanum or "_"
	for (i =0; i < len; i++)
	{
		//caractère de a à z
		if (id[i]  >= 97 && id[i] <= 122 ){	
		}
		//caractère de 0 à 9
		else if (id[i]  >= 48 && id[i] <= 57) {
		}
		//caractère underscore
		else if (id[i]  == 95) {
		}
		else {return false;}
	}
	return true;
}

    void Lexeme::operator=(const string & b){
	this->setName(b);
}

    string Lexeme::toString() const { 
	stringstream info;
	info <<getName();   
	return info.str();
}

    //Fonctions amies
    ostream& operator<<(ostream& out, const Lexeme &l){
	out << l.toString();
	return out;
}


    

