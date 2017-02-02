#include "./../Header/Node_root.h"
#include "./../Header/Node_library.h"
#include "./../Header/Node_libraryUse.h"
#include "./../Header/Node_entity.h"
#include "./../Header/Node_architecture.h"


//builders
	Node_root::Node_root(list<Lexeme> parsing, list<Lexeme>::iterator it):Node("Root",it){
		cout << endl << "		###################################"<< endl
			     << " 			Begin tree built  "  	    << endl
			     << "		###################################"<< endl << endl;
		//cout << "--- Begin of creation : " << getLabel()<< endl;
		structure = parsing;
		createSons();
		//cout << "--- End of creation : " << getLabel()<< endl;
	}

	Node_root::~Node_root(){}

//methods
	void Node_root::createSons(){
		list<Lexeme>::iterator iter;
		list<Lexeme>::iterator iter_endOfList = structure.end();
		bool asSon = false;

		for (iter = structure.begin(); iter != structure.end(); iter++){
			if(((*iter).getName() == "library") and ((*iter).getType() == "keyword")){
				cout <<"	>>> Add "<< getLabel() <<" son : Library"<< endl;
				sons.push_back(new Node_library(iter));
			}
			else if((*iter).getName() == "use" and ((*iter).getType() == "keyword")){
				cout <<"	>>> Add "<< getLabel() <<" son : LibraryUse"<< endl;
				sons.push_back(new Node_libraryUse(iter));	
			}
			else if((*iter).getName() == "entity" and ((*iter).getType() == "keyword")){
				cout <<"	>>> Add "<< getLabel() <<" son : Entity"<< endl;
				sons.push_back(new Node_entity(iter));	
			}
			else if((*iter).getName() == "architecture" and ((*iter).getType() == "keyword")){
				cout <<"	>>> Add "<< getLabel() <<" son : Architecture"<< endl;
				sons.push_back(new Node_architecture(iter,iter_endOfList));
			}
		}
	
		if (sons.size() == 0){
			cout<< getLabel()<< " has no son"<< endl;
		}
	}

	bool Node_root::checkStruct(){} //Node virtual pure function not used for this class : structure checking is made during parsing
	void Node_root::createStruct(){}//Node virtual pure function not used for this class : structure copied from VHDL source parsing

