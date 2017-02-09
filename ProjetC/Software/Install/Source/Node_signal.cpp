#include "./../Header/Node_signal.h"
#include "./../Header/Node_signalScalaire.h"
#include "./../Header/Node_signalComposite.h"


//builders
	Node_signal::Node_signal(list<Lexeme>::iterator it):Node("Signal",it){
		//cout << "--- Begin of creation : " << getLabel()<< endl;
		createStruct();
		checkStruct();
		if (sons.size() == 0){
			cout<< getLabel()<< " has no son"<< endl;
		}
		//cout << "--- End of creation : " << getLabel()<< endl;	
	}

	Node_signal::~Node_signal(){}

//methods
	void Node_signal::createScalaire(list<string> names, string initValue, string type){
		list<string>::iterator it;
	
		for(it = names.begin(); it != names.end(); it++){
			sons.push_back(new Node_signalScalaire(lex_it,*it,initValue,type));
		}
	}

	void Node_signal::createComposite(list<string> names, string initValue, string type, string lowerBound, string upperBound){
		list<string>::iterator it;
	
		for(it = names.begin(); it != names.end(); it++){
			sons.push_back(new Node_signalComposite(lex_it,*it,initValue,type, lowerBound,upperBound));
		}	
	}

	void Node_signal::createStruct(){
		list<Lexeme>::iterator it;
		for (it = lex_it; (*it).getName() != ";"; it++){
			structure.push_back((*it).getName());
		}
		structure.push_back(Lexeme(";"));
	}

	bool Node_signal::checkStruct(){
		list<Lexeme>::iterator it;
		list<Lexeme>::iterator it_tmp;
		
		bool countWay=true;
		string tmpBound;
		int step = 0;

		cout << "							Start SIGNAL structure validation"<< endl;
		for(it = structure.begin(); it != structure.end(); it ++)
		{
			it_tmp = it;
			//cout << step << " | " << *it <<endl;

	///////////////////////////////////////////CHECKSTRUCTURE SIGNAL///////////////////////////////////////////
			switch(step){		
				case 0:		if((*it).getName()=="signal"){step++;}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}	//rentre dans le cas default
			
						break;

				//Case 2 et 3 parcourt les Id avant le ":"
				case 1 :   	if((*it).getType()=="id"  and (*++it_tmp).getName() == ","){
							names.push_back((*it).getName());
							step++;
						}
						else if((*it).getType()=="id"  or (*++it_tmp).getName() == ":"){
							names.push_back((*it).getName());
							step +=2;
						}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 2 :        //Si id après "," on repart en 2. 
						if((*++it_tmp).getType()=="id") {step--;}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;
	

				case 3 :     	if((*it).getName()==":"){step++;}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				//Détermination du type du signal [composite ou scalaire]
				case 4 :       type = (*it).getName();
						///////////////////////////////////////////
						//Bit avec initialisation
						if((*it).getName()== "bit") {
							if ((*++it_tmp).getName()== ":"){
							step = 10;
							}
							else step = 7;
						}

						///////////////////////////////////////////
						//std_logic avec initialisation
						else if((*it).getName()== "std_logic"){
							if ((*++it_tmp).getName()== ":"){
								step = 15;
							}
							else step = 7;
						}
						///////////////////////////////////////////
						//integer avec initialisation
						else if((*it).getName()== "integer"){
							if ((*++it_tmp).getName()== "range"){
								step = 20;
						}
							else step = 7;
						}
						///////////////////////////////////////////
						//string avec initialisation
						else if((*it).getName()== "string"){
							step = 30;
						}

						///////////////////////////////////////////
						//boolean avec initialisation
						else if((*it).getName()== "boolean") {
							if ((*++it_tmp).getName()== ":"){
								step = 40;
							}
							else step = 7;
						}
						///////////////////////////////////////////
						//bit_vector avec initialisation
						else if((*it).getName()== "bit_vector"){
							step = 50;
						}

						///////////////////////////////////////////
						//std_logic_vector avec initialisation
						else if((*it).getName()== "std_logic_vector"){
							type = (*it).getName();
							step = 50;
						}
				
						else step = -1;
						break;
			
				//Bit
				case 10 :       if((*it).getName() == ":"){step++;}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 11:       if((*it).getName() == "="){step++;}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 12 :       if((*it).getName() == "'"){step++;}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 13 :       if(isEntier((*it).getName())){
							initValue = (*it).getName();
							step++;
						}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 14 :       if((*it).getName() == "'"){step = 7;}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				//std_logic
				case 15 :       if((*it).getName() == ":"){step++;}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 16:       if((*it).getName() == "="){step++;}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 17 :       if((*it).getName() == "'"){step++;}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 18 :       if(isStd_Logic((*it).getName())){
							initValue = (*it).getName();
							step++;
						}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 19 :       if((*it).getName() == "'"){step = 7;}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

			
				//INTEGER avec range
				case 20 :       if((*it).getName() == "range"){step++;}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;
							
				case 21 :       if(isEntier((*it).getName())){
							lowerBound = (*it).getName();
							step++;
						}

						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 22 :       if((*it).getName()== "to"){
							step++;
						}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 23 :       if(isEntier((*it).getName()) and (*++it_tmp).getName() == ";"){
							upperBound = (*it).getName();
							step = 7;
						}
						else if(isEntier((*it).getName()) or (*++it_tmp).getName() == ":"){step++;}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 24 :       if((*it).getName() == ":"){step++;}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 25 :       if((*it).getName() == "="){step++;}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 26 :       if(isEntier((*it).getName())){
							initValue=(*it).getName();
							step = 7;
						}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				//String avec TO
				case 30 :       if((*it).getName() == "("){
							step++;
						}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 31 :       if(isEntier((*it).getName())){
							lowerBound=(*it).getName();
							step++;
						}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 32 :       if((*it).getName()== "to"){

							step++;
						}

						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 33 :       if(isEntier((*it).getName())){
							upperBound=(*it).getName();
							step++;
						}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 34 :      	if((*it).getName()== ")" and (*++it_tmp).getName() == ";"){
	
							step = 7;
						}
						else if((*it).getName()== ")" or (*++it_tmp).getName() == ":"){

							step++;
						}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 35 :       if((*it).getName() == ":"){step++;}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 36 :       if((*it).getName() == "="){step++;}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 37 :       if((*it).getName() == "\""){step++;}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 38 :       if(isString((*it).getName())){
							initValue=(*it).getName();
							step++;
						}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 39 :       if((*it).getName() == "\""){step = 7;}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				//BOOLEAN
				case 40 :       if((*it).getName() == ":"){step++;}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 41:       if((*it).getName() == "="){step++;}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;


				case 42 :       if((*it).getName() == "false"){
							initValue=(*it).getName();
							step = 7;
						}
						else if((*it).getName() == "true"){
							initValue=(*it).getName();
							step = 7;
						}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;


				//VECTOR avec up/down
				case 50 :       if((*it).getName() == "("){
							step++;
						}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 51 :       if(isEntier((*it).getName())){
							lowerBound=(*it).getName();
							step++;
						}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 52 :       if((*it).getName()== "to"){
							countWay = true;
							step++;
						}
						else if((*it).getName()== "downto"){
							countWay = false;
							step++;
						}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 53 :       if(isEntier((*it).getName())){
							lowerBound=(*it).getName();
							step++;
						}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 54 :      	if((*it).getName()== ")" and (*++it_tmp).getName() == ";"){step = 7;}
						else if((*it).getName()== ")" or (*++it_tmp).getName() == ":"){step++;}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 55 :       if((*it).getName() == ":"){step++;}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 56 :       if((*it).getName() == "="){step++;}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 57 :       if((*it).getName() == "\""){step++;}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 58 :       if(isEntier((*it).getName())){
							initValue=(*it).getName();
							step++;
						}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				case 59 :       if((*it).getName() == "\""){step = 7;}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				//Fin du SIGNAL
				case 7 :        if((*it).getName()==";") {	
							if(type== "bit" or type =="std_logic"){
								cout << "			>>>> Create Signal son :" << endl << "				signalScalaire" << endl;
								createScalaire(names,initValue,type); 
								names.clear();
								initValue.clear();
								type.clear();
							}
							else{
								if (!countWay){ //if range is downto type ; exchange upper and lower Bounds
									tmpBound=lowerBound; 
									lowerBound = upperBound;
									upperBound = tmpBound;
								}
								cout << "			>>>> Create Signal son :" << endl << "				signalComposite" << endl;
								createComposite(names,initValue,type,lowerBound,upperBound);
								names.clear();
								initValue.clear();
								type.clear();
								lowerBound.clear();
								upperBound.clear();
							}
							cout << "							Structure SIGNAL OK" << endl;
							return true;
						}
						else {
							step=-1;
							cout << (*it).getName() << " n'est pas une valeur recevable !" << endl;
						}
						break;

				default :	cout << "							error" << endl; //cf gestion d'erreur
						return false;		  
			}
		}
	}

	string  Node_signal::displaySonsAndAttributes() const {  
		vector<Node*>::const_iterator it;
		stringstream mySons;

		mySons << "	----Sons----" << endl;
		for (it = sons.begin(); it != sons.end(); it++){ 
			mySons << "			"  << (*it)->getLabel() << " : " ;
			if ((*it)->getLabel()=="SignalScalaire"){
				mySons << endl
				       << "				"<<(*it)-> getName()<< endl
				       << "				"<<(*it)-> getInitValue()<< endl
				       << "				"<<(*it)-> getType()<< endl;
			}
			else if ((*it)->getLabel()=="SignalComposite"){
				mySons << endl
				       << "				"<<(*it)-> getName()<< endl
				       << "				"<<(*it)-> getInitValue()<< endl
				       << "				"<<(*it)-> getType()<< endl
				       << "				"<<(*it)-> getLowerBound()<< endl
				       << "				"<<(*it)-> getUpperBound()<< endl;
			}	
		}
		return mySons.str();
	}



