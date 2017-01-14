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
	

    //Methodes
    void Lexeme::associateType(){
	//cout << "dans associateType : "<< name << endl;
				
	for(int i = 0; i < N ; i++){	
		if(name == keywordList[i]){
			//cout<< "dans Keyword" << endl; 
			type = "keyword";
			break;
		}
		else if (name[0] == specialList[i]){
			//cout<< "dans Special" << endl; 
			type = "special";
			break;
		}
		else if (name == operatorList[i]){
			//cout<< "dans Special" << endl; 
			type = "special";
			break;
		}
		else{
			
		}
	}	
    }

    bool Lexeme::validIdentifier() {
	int len = this->getName().size();
	string id = getName();
	
	int i;
	if (id[0] == 95) {return false;}
	else if (id[len-1] == 95) {return false;}
	else if (id[0]  >= 48 && id[0] <= 57 ){return false;}

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


    

