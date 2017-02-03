#include "./../Header/Node_declaration.h"
#include "./../Header/Node_signal.h"
#include "./../Header/Node_variable.h"
#include "./../Header/Node_component.h"
#include "./../Header/Node_type.h"


//builders
	Node_declaration::Node_declaration(list<Lexeme>::iterator it):Node("Declaration",it){
		//cout << "--- Begin of creation : " << getLabel()<< endl;
		createStruct();
		createSons();
		shapeStruct();
		checkStruct();
		//cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_declaration::~Node_declaration(){}

//methods
	void Node_declaration::createSons(){
		list<Lexeme>::iterator iter;

		for (iter = structure.begin(); iter != structure.end(); iter++){
			if(((*iter).getName() == "signal") and ((*iter).getType() == "keyword")){
				cout <<"		>>> Create "<< getLabel() <<" son : signal"<< endl;
				sons.push_back(new Node_signal(iter));
			}
			else if(((*iter).getName() == "variable") and ((*iter).getType() == "keyword")){
				cout <<"		>>> Create "<< getLabel() <<" son : variable"<< endl;
				sons.push_back(new Node_variable(iter));
			}
			else if(((*iter).getName() == "component") and ((*iter).getType() == "keyword")){
				cout <<"		>>> Create "<< getLabel() <<" son : component"<< endl;
				sons.push_back(new Node_component(iter));
			}
			else if(((*iter).getName() == "type") and ((*iter).getType() == "keyword")){
				cout <<"		>>> Create "<< getLabel() <<" son : type"<< endl;
				sons.push_back(new Node_type(iter));
			}

			if (sons.size() == 0){
				cout<< "			---"<< getLabel()<< " has no son"<< "---" << endl;
			}	
		}
	}

	void Node_declaration::createStruct(){
		list<Lexeme>::iterator it;
		for (it = lex_it; (*it).getName() != "begin"; it++){
			structure.push_back((*it).getName());
		}
	}

	void Node_declaration::shapeStruct(){
		list<Lexeme>::iterator iter;

		for (iter = structure.begin(); iter != structure.end(); iter++){
			if(((*iter).getName() == "signal") and ((*iter).getType() == "keyword")){
				cutStruct(Lexeme("signal"),Lexeme(";"));
				structure.pop_back();	
			}
			else if(((*iter).getName() == "variable") and ((*iter).getType() == "keyword")){
				cutStruct(Lexeme("variable"),Lexeme(";"));
				structure.pop_back();
			}
			else if(((*iter).getName() == "component") and ((*iter).getType() == "keyword")){
				cutStruct(Lexeme("component"),Lexeme(";"));
				structure.pop_back();
			}
			else if(((*iter).getName() == "type") and ((*iter).getType() == "keyword")){
				cutStruct(Lexeme("type"),Lexeme(";"));
				structure.pop_back();
			}
		}	
	}

	bool Node_declaration::checkStruct(){
		list<Lexeme>::iterator it;
		list<Lexeme>::iterator it_tmp;
		int step = 0;

		cout << "							Start DECLARATION structure validation"<< endl;
		for(it = structure.begin(); it != structure.end(); it ++)
		{
			it_tmp = it;
			//cout << step << " | " << *it <<endl;
///////////////////////////////////////////CHECKSTRUCTURE DECLARATION///////////////////////////////////////////
			switch(step){		
				case 0:		if((*it).getName()=="signal" 
						or (*it).getName()=="variable" 
						or (*it).getName()=="component" 
						or (*it).getName()=="type") {step = 0;}

						else {
							cout << "error" << endl; //cf gestion d'erreur
							return false;	//rentre dans le cas default
						}
						break;

				default :	cout << "							error" << endl; //cf gestion d'erreur
						return false;		  
			}
		}
			cout << "							Structure DECLARATION OK" << endl; 
			return true;
	}


	string  Node_declaration::displaySonsAndAttributes() const {  
		vector<Node*>::const_iterator it;
		stringstream mySons;

		mySons << "	----Sons----" << endl; 
		for (it = sons.begin(); it != sons.end(); it++){
			mySons << "				"  << (*it)->getLabel() << endl;
		}
		return mySons.str();
	}


