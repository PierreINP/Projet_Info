#include "./../Header/Node_library.h"
#include "./../Header/Node_libraryUse.h"

//builders
	Node_library::Node_library(list<Lexeme>::iterator it):Node("Library",it){
		cout << "--- Begin of creation : " << getLabel()<< endl;
		createStruct();
		createSons();
		checkStruct();
		cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_library::~Node_library(){}

//methods
	void Node_library::createSons(){} //No son

	void Node_library::createStruct(){
		list<Lexeme>::iterator it;

		for (it = lex_it; (*it).getName() != "use"; it++){
			structure.push_back((*it).getName());			
		}
	}

	bool Node_library::checkStruct(){
		list<Lexeme>::iterator it;
		list<Lexeme>::iterator it_tmp;
		int step = 0;

		cout << "   ** Start LIBRARY structure validation **   "<< endl;
		for(it = structure.begin(); it != structure.end(); it ++)
		{
			it_tmp = it;
			cout << step << " | " << *it <<endl;
	///////////////////////////////////////////CHECKSTRUCTURE LIBRARY///////////////////////////////////////////
			switch(step){		
				case 0:		if((*it).getName()=="library"){step++;}
						else step=-1;	//rentre dans le cas default
						break;

				case 1:		if((*it).getType()=="id"){
							library_ID = (*it).getName();
							step++;
						}
						else step=-1;	
						break;

				case 2:		if((*it).getName()==";"){
							cout << "Structure LIBRARY validée" << endl;
							return true;
						}
						else if((*++it_tmp).getName()=="library"){step=0;}
						else return false;	
						break;

				default :	cout << "error" << endl; //cf gestion d'erreur
						return false;		  
			}

		}
	}

	//accessors
		const string & Node_library::getLibraryID()const{
			return library_ID;
	}


