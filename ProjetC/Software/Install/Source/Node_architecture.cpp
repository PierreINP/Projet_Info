#include "./../Header/Node_architecture.h"

//builders
Node_architecture::Node_architecture(list<Lexeme>::iterator it, list<Lexeme>::iterator itEnd):Node("Architecture",it), end_it(itEnd){
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

Node_architecture::~Node_architecture(){}

//methods
void Node_architecture::createSons(){}
void Node_architecture::createStruct(){
	list<Lexeme>::iterator it;
	
	for (it = lex_it; it != end_it; it++){
		structure.push_back((*it).getName());
	}
}
bool Node_architecture::checkStruct(){}

//accessors
const string & Node_architecture::getEntityID()const{
	return entity_ID;
}

const string & Node_architecture::getArchitectureID()const{
	return architecture_ID;
}



