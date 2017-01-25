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

//methods
void Node::shapeStruct(Lexeme cutBegin, Lexeme cutEnd){
	list<Lexeme>::iterator it;

	//structure.remove(cutBegin.getName());
	for(it = structure.begin(); it != structure.end();it++){
		//cout << *it;
		if((*it).getName() == cutBegin.getName()){
			//structure.remove(*it);
			while((*it).getName() != cutEnd.getName()){
				//cout<<(*it)<< " ";	
				structure.remove((*it));
				it++;
			}
		}		
	}
}

string  Node::displaySons() const {  
	vector<Node*>::const_iterator it;
	stringstream sons;

	sons << "Current node " << getLabel() << " has following sons : "<< endl; 
	for (it = enfants.begin(); it != enfants.end(); it++){
		sons << (*it)->getLabel() << endl;
	}
	return sons.str();
}

string  Node::displayStruct() const {  
	list<Lexeme>::const_iterator it;
	stringstream struc;

	struc << "Current node " << getLabel() << " has following lexemes structure : "<< endl; 
	for (it = structure.begin(); it != structure.end(); it++){
		struc << *it << " " ; // display lexemes names composing current instance
	}
	return struc.str();
}

//friend function
 ostream& operator<<(ostream& out, const Node &n){
	out << n.displaySons()<< endl;
	return out;
}

