/*
This programm is here to perform some functions. It must identify the lexemes, compute them to validate their conformity and then give them a type. 
Input : SourceFile.vhd
Output : Data structure
*/

#include"./../Header/Lexeur.h"
#include "./../Header/Lexeme.h"
#define path_size 100

// A MAINTENIR A JOUR
#define nb_separator 10
#define nb_operator 15

extern string keywordList[];
extern char specialList[];
extern string operatorList[];

list<Lexeme> readSource(char* file)
{
	std::list<Lexeme> lexeme_list; //list of lexeme, contains list of words
	std::list<Lexeme> my_list; //list of lexeme, contains list of words
	Lexeme tmp;
	ifstream sourcecode(file); //Input Stream from file named sourcecode 
	string line; //line red in the file

	if (sourcecode == NULL) {
		cout << "Source code : " << file << " can't be openned\n";
		//GESTION D'ERREUR ? flags montés dans une fonction exterieure
	}
	else {
		cout << "Source code openned\n";
		int i;
		while (getline(sourcecode, line)) // reads the line
    		{	
			cout << i++  << " | "<< line << endl;
			my_list = split_line(line);
			while(my_list.size() != 0) {
				tmp = my_list.front();
				//cout << "TMP" <<tmp <<endl;
				lexeme_list.push_back(tmp);
				my_list.pop_front();
			}
			
		}
	}			
sourcecode.close(); // Closing the input file stream
return lexeme_list;
}


string suppressCommentary(string& line) {
	int flag = -1;
	string new_line;

	flag = line.find("--");
	line = line.substr(0, flag);	

	//cout << line << endl;// << new_line << endl;
return line; 
}


//Remplace in a ligne horizontal tab by space character
string eraseTab(string line) {
	int i;
	string new_line;
	for (i=0; i < line.size(); i++) {
		if (line[i]!=9) {		
			new_line += line[i];
		}
		else {		
			new_line += " ";
		}	
	}
	new_line += "\0";
	//cout << line << endl << new_line << endl;
return new_line; 
}

list<Lexeme> split_line(string line) 
{
	std::list<Lexeme> my_list; //list of lexeme, contains list of words

	int r = 0;
	int i;

	line = suppressCommentary(line);
	//line = eraseTab(line);

	int sep, ope, filler;
	//cout << "Line of " << size << " characters" << endl;
	//cout << line << endl;

	for(i = 0; i < line.size(); i++) {
		//suppression des tabulations dans le Lexeme final
		if (line[i] == 9) {r++;}
		else if (line[i] == 0) {r++;}
		//séparation de la ligne si on rencontre un espace + saut de l'espace
		else if(line[i]== 32) {
		     Lexeme word(line.substr(r, i-r));
		     my_list.push_back(word);
      		     r=i+1;
    		}
		else {
			//Séparation char pour specialList			
			for (sep = 0; sep < nb_separator; sep++) {
				if(line[i]== specialList[sep]) {
				     //séparation de la ligne si on rencontre un separateur + saut du séparateur
				     Lexeme word(line.substr(r, i-r));
				     my_list.push_back(word);
				     //cout << "MOT  : " << word << endl;
				     //Création d'un lexeme pour le séparateur
				     Lexeme separator(line[i]);
				     my_list.push_back(separator);
				     //cout << "SEP  : " << separator << endl;
				     r=i+1;
		      		     
		    		}
			}
		}
	}
 	
	
Lexeme fin(line.substr(r, line.size()-r));
my_list.push_back(fin);
return my_list;
}


list<Lexeme> clearList (list<Lexeme> old_list) {

	/*
	IN : lexeme List
	OUT : lexeme list
	this function takes the splitted lexeme list, It creates a new list avoiding all the empty elements created during split
	*/		

	std::list<Lexeme> cleared_list;
	std::list<Lexeme> tmp_list;
	list<Lexeme>::iterator iter; 

	tmp_list = old_list;

	for(iter = old_list.begin(); iter != old_list.end(); iter ++)
	{
		if (iter->getName()[0] == 0) {
			tmp_list.pop_front();
		}
		else {
			cleared_list.push_back(tmp_list.front());
			tmp_list.pop_front();
		}
	}
	//cout << "list1 : " << old_list.size()<< endl << "list2 : " << cleared_list.size()<< endl;
	return cleared_list;
}


bool alphanum(char a) {
	if (a >= 97 and a <=122) {return true;}
	else {return false;}
}

list<Lexeme> checkLexeme(list<Lexeme> old_list) {
	/*
	IN : lexeme List
	OUT : lexeme list
	this function takes the lexeme list cleaned. Final vérif : séparation si un opérateur dans le lexeme + associate type + verif ID 
	*/

	std::list<Lexeme> final_list;
	std::list<Lexeme> tmp_list;
	list<Lexeme>::iterator iter;
	list<Lexeme>::iterator local_iter; 

	int ope;
	int pos = 0;

	

	for(iter = old_list.begin(); iter != old_list.end(); iter ++)
	{
		tmp_list.clear();
		//cout << *iter << endl;
		
		(*iter).associateType();
		//Prend les id, dont ceux qui contiennent un operateur collé dans la même string
		if ((*iter).getType() == "id") {
			//Pour chaque opérateur, verifier si il est présent dans la string
			for (ope = 0; ope < nb_operator; ope++) {
				pos = (*iter).getName().find(operatorList[ope]);
				size_t taille_mot = (*iter).getName().size();
				string lex = (*iter).getName();

				//Si il est present après le lexeme, découpe operateur puis id + insertion dans la liste
				if (pos != -1 and alphanum(lex[0])) {
					// {}
					Lexeme operateur(lex.substr(pos, lex.size()));
					Lexeme mot(lex.substr(0, pos));
					tmp_list.push_back(mot);
					tmp_list.push_back(operateur);
					
					old_list.splice(iter, tmp_list);
					//cout << "ORIGIN : " << lex << " POS : " << pos << " MOT : " << mot << " OPE : " << operateur << endl;
					break;
				}
				//Si il est present au début du lexeme : découpe operateur puis id + insertion dans la liste
				else if (pos == 0) {
					Lexeme mot(lex.substr(operatorList[ope].size() , lex.size() ));
					Lexeme operateur(lex.substr(pos, operatorList[ope].size() ));
					tmp_list.push_back(operateur);
					tmp_list.push_back(mot);

					old_list.splice(iter, tmp_list);
					//cout << "ORIGIN : " << lex << " POS : " << pos << " MOT : " << mot << " OPE : " << operateur << endl;
					break;
				}
			}
		}
	}

	final_list = old_list;

	//suppression de l'id faussé avec un operateur collé.
	for(iter = final_list.begin(); iter != final_list.end(); iter ++)
	{
		(*iter).associateType();
		if ((*iter).getType() == "id") {
			for (ope = 0; ope < nb_operator; ope++) {
				pos = (*iter).getName().find(operatorList[ope]);
				if (pos != -1) {
					//cout << (*iter).getName() << endl;
					old_list.remove((*iter).getName());
					break;
				}
			}
		}
	}

return old_list;
}

