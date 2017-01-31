#include "./../Header/Node_libraryUse.h"

//builders
	Node_libraryUse::Node_libraryUse(list<Lexeme>::iterator it):Node("LibraryUse",it){
		cout << "--- Begin of creation : " << getLabel()<< endl;
		createStruct();
		createSons();
		checkStruct();
		cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_libraryUse::~Node_libraryUse(){}

//methods
	void Node_libraryUse::createSons(){}//no son

	void Node_libraryUse::createStruct(){
		list<Lexeme>::iterator it;

		for (it = lex_it; (*it).getName() != ";" ; it++){
			structure.push_back((*it).getName());
		}
		structure.push_back(Lexeme(";"));
	}

	bool Node_libraryUse::checkStruct(){
		list<Lexeme>::iterator it;
		list<Lexeme>::iterator it_tmp;
		int step = 0;

		for(it = structure.begin(); it != structure.end(); it ++)
		{
			it_tmp = it;
			cout << step << " | " << *it <<endl;
	///////////////////////////////////////////CHECKSTRUCTURE LIBRARY USE///////////////////////////////////////////
			switch(step){		
				case 0:		if((*it).getName()=="use"){step++;}
						else step=-1;	//rentre dans le cas default
						break;

				case 1:		if((*it).getType()== "id" ){
							
							/* if(library_name == (*it).getName()){}
							else step=-1;*/
							step++;
						}
						else step=-1;
						break;

				case 2:		if((*it).getName()=="."){step++;}
						else step=-1;
						break;
	
				case 3:		if((*it).getType()== "id"){
							library_ID = (*it).getName();
							step++;
						}
						else step=-1;
						break;	

				case 4:		if((*it).getName()=="."){step++;}
						else step=-1;
						break;
					
				case 5:		if((*it).getType()== "id" or (*it).getName()== "all"){
							package = (*it).getName();
							step++;
						}
						else step=-1;
						break;

				case 6 :        if((*it).getName()==";"){
							cout << "Structure LIBRARY USE validée" << endl;
							return true;
						}
						else return false;
						break;    
					

				default :	cout << "error" << endl; //cf gestion d'erreur
						return false;		  
			}
		}
	}

//accessors
	const string & Node_libraryUse::getLibraryID()const{
		return library_ID;
	}

	const string & Node_libraryUse::getPackage()const{
		return package;
	}


