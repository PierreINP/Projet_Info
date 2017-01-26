#include "./../Header/Node.h"

//builders
	Node::Node(string l, list<Lexeme>::iterator it): label(l),lex_it(it){}
	Node::~Node(){}

//accessors
	const string & Node::getLabel()const{
		return label;
	}

	const list<Lexeme>::iterator & Node::getLexIt()const{
		return lex_it;
	}

	const vector<Node*> Node::getSons()const{
		return sons;
	}
//methods
	void Node::shapeStruct(Lexeme cutBegin, Lexeme cutEnd){
		list<Lexeme>::iterator it;
		list<Lexeme> structure_tmp;

		for(it = structure.begin(); it != structure.end();it++){
			if((*it).getName() == cutBegin.getName()){
				structure_tmp.push_back(*it);
				do {		
					it++;
				}
				while(((*it).getName() != cutEnd.getName()) and (it != structure.end()));
			}
			structure_tmp.push_back(*it);	
		}
		structure = structure_tmp;
	}

	bool Node::isEntier(string a) {
		int i;

		for (i; i< a.size(); i++) {
			if (not(a[i] >= 48 and a[i] <= 57)) {return false;} 
		}
		return true;
	}


	string  Node::displaySons() const {  
		vector<Node*>::const_iterator it;
		stringstream mySons;

		mySons << "Node " << getLabel() << " has following sons : "<< endl; 
		for (it = sons.begin(); it != sons.end(); it++){
			mySons << (*it)->getLabel() << endl;
		}
		return mySons.str();
	}

	string  Node::displayStruct() const {  
		list<Lexeme>::const_iterator it;
		stringstream struc;

		struc << "Node " << getLabel() << " has following lexemes structure : "<< endl; 
		for (it = structure.begin(); it != structure.end(); it++){
			struc << *it << " " ; // display lexemes names composing current instance
		}
		return struc.str();
	}

//friend function
	 ostream& operator<<(ostream& out, const Node &n){
		out << n.displaySons()<< endl << n.displayStruct();
		return out;
	}

