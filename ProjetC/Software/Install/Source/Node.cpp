#include "./../Header/Node.h"

//builders
	Node::Node(string l, list<Lexeme>::iterator it): label(l),lex_it(it){}
	Node::~Node(){}

//methods

	void Node::shapeStruct(){}	// virtual
	void Node::createSons(){}	// virtual

	void Node::cutStruct(Lexeme cutBegin, Lexeme cutEnd){
		list<Lexeme>::iterator it;
		list<Lexeme> structure_tmp;

		for(it = structure.begin(); it != structure.end();it++){
			if((*it).getName() == cutBegin.getName()){
				structure_tmp.push_back(*it);
				do {it++;}
				while(((*it).getName() != cutEnd.getName()) and (it != structure.end()));
				if(cutBegin == cutEnd){it++;it++;}//delete duplicate & lexeme after that
			}
			structure_tmp.push_back(*it);	
		}
		structure = structure_tmp;
	}

	//Vérifie si chaque caractère d'un lexeme est un chiffre
	bool Node::isEntier(string a) {
		int i;

		for (i; i< a.size(); i++) {
			if (not(a[i] >= 48 and a[i] <= 57)) {
				return false;
			} 
		}
		return true;
	}

	//Vérifie si chaque caractère d'un lexeme est un chiffre
	bool Node::isString(string a) {
		int i;
		for (i; i< a.size(); i++) {
			if (not(a[i] >= 97 and a[i] <= 122)){
				return false;
			} 
		}
		return true;
	}

	//Vérifie si chaque caractère d'un lexeme est un type reconnu de std logic
	bool Node::isStd_Logic(string a) {
		char tab_type[10] = {"ux01zwlh-"};
		int i;

		for (i=0; i <9; i++) {
			//cout << "LEX " << a[0] << " TYPE? " << tab_type[i] <<endl;
			if(a[0] == tab_type[i]){
				return true;
			}
		}
		return false;
	}

	string  Node::displaySonsAndAttributes() const {  
		vector<Node*>::const_iterator it;
		stringstream mySons;

		mySons << "	----Sons----" << endl; 
		for (it = sons.begin(); it != sons.end(); it++){
			mySons << "				"  << (*it)->getLabel() << endl;
		}
		return mySons.str();
	}

	string  Node::displayStruct() const {  
		list<Lexeme>::const_iterator it;
		stringstream struc;

		struc << "	----Structure----" << endl; 
		for (it = structure.begin(); it != structure.end(); it++){
			struc << *it << " " ; // display lexemes names composing current instance
		}
		return struc.str();
	}

	string Node::toString() const {
		stringstream flow;
		flow<< "################################################################################"<< endl
		    << "  		  		 Node "<< getLabel()  << endl
		    << "################################################################################"<< endl
		    << "			" << displaySonsAndAttributes() ;
		return flow.str();
	}

	//accessors
	const string & Node::getLabel()const{return label;}
	const list<Lexeme>::iterator & Node::getLexIt()const{return lex_it;}
	const vector<Node*> Node::getSons()const{return sons;}
	//virtuals
	const string & Node::getLibraryID()const{}
	const string & Node::getPackage()const{}
	const string & Node::getEntityID()const{}
	const string & Node::getName()const{} 		
	const string & Node::getDirection()const{}	
	const string & Node::getType()const{}		
	const string & Node::getLowerBound()const{}	
	const string & Node::getUpperBound()const{}	
	const string & Node::getArchitectureID()const{}
	const string & Node::getInitValue()const{}

	//friend function
	 ostream& operator<<(ostream& out, const Node &n){
		out << n.toString();
		return out;
	}

