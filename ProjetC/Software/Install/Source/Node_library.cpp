#include "./../Header/Node_library.h"
#include "./../Header/Node_libraryUse.h"

//builders
Node_library::Node_library(list<Lexeme>::iterator it):Node("Library",it){
	createStruct();
	cout <<"before shaping : " << displayStruct()  <<endl;
	createSons();
	//shapeStruct();
	cout <<endl<<"after shaping : " << displayStruct()  <<endl<<"---(Not implemented yet)---"<<endl;
	/*if(checkStruct() == true){
		cout << "	-> correct structure syntax"<< endl;
	}
	else {
		cout << "	-> incorrect structure syntax"<< endl;
	}*/
	cout << ">>> End of " << getLabel()<< " creation" << endl;
}

Node_library::~Node_library(){}

//methods
void Node_library::createSons(){
	list<Lexeme>::iterator iter;

	for (iter = structure.begin(); iter != structure.end(); iter++){
		if(((*iter).getName() == "use") and ((*iter).getType() == "keyword")){
			cout <<endl<<">>> Add Library son : libraryUse"<< endl;
			enfants.push_back(new Node_libraryUse(iter));
		}
	}
}
void Node_library::createStruct(){
	list<Lexeme>::iterator it;

	for (it = lex_it; (*it).getName() != "entity"; it++){
		structure.push_back((*it).getName());			
	}
}

bool Node_library::checkStruct(){}

//accessors
const string & Node_library::getLibraryID()const{
	return library_ID;
}


