/*
This programm is here to perform some functions. It must identify the lexemes, compute them to validate their conformity and then give them a type. 
Input : SourceFile.vhd
Output : Data structure
*/

#include"./../Header/Lexeur.h"
#include "./../Header/Lexeme.h"
#define path_size 100
#define nb_separator 10
#define nb_operator 16

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

list<Lexeme> split_line(string line) 
{
	std::list<Lexeme> my_list; //list of lexeme, contains list of words

	int size = line.size();
	int r = 0;
	int i;

	int sep, ope;
	//cout << "Line of " << size << " characters" << endl;
	//cout << line << endl;

	for(i = 0; i < size; i++) {
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
				     //séparation de la ligne si on rencontre un espace + saut du séparateur
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

			/*
			Séparation pour operatorList	
			Gestion des opérateurs char mais aussi opérateurs avec size > 1 (check de list[i] et list [i+1]) ...
			*/

			/*	
			for (ope = 0; ope < nb_operator; ope++) {
				size_t len_ope = operatorList[ope].size();
					
				if(len_ope == 1) {
			 	     if (line[i] == operatorList[ope][0]) {
					     //séparation de la ligne si on rencontre un espace + saut du séparateur
					     Lexeme word(line.substr(r, i-r));
					     my_list.push_back(word);
					     //Création d'un lexeme pour le séparateur
					     Lexeme separator(line[i]);
					     my_list.push_back(separator);
					     r=i+1;
				     }
		      		     
		    		}
				else if(len_ope == 2) {
				     if (line[i]== operatorList[ope][0] and line[i+1]== operatorList[ope][1]) {
					     //séparation de la ligne si on rencontre un espace + saut du séparateur
					     Lexeme word(line.substr(r, i-r));
					     my_list.push_back(word);
					     //Création d'un lexeme pour le séparateur
					     Lexeme separator(line.substr(i, i+len_ope-1));
					     my_list.push_back(separator);
					     r=i+1;
		      		     }
		    		}
			}*/



	
		}  	
	}
Lexeme fin(line.substr(r, size-r));
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

