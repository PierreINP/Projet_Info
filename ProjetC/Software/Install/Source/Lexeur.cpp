/*
This programm is here to perform some functions. It must identify the lexemes, compute them to validate their conformity and then give them a type. 
Input : SourceFile.vhd
Output : Data structure
*/

#include"./../Header/Lexeur.h"
#include "./../Header/Lexeme.h"
#define path_size 100
#define nb_separator 10

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

	int sep;
	//cout << "Line of " << size << " characters" << endl;
	//cout << line << endl;

	for(i = 0; i < size; i++) {
		if(line[i]== 32) {
		     Lexeme word(line.substr(r, i-r));
		     cout << "MOT1 : "<< word.getName() << endl;
		     word.avoidSpace();
	  	     cout << "MOT2 : "<< word.getName() << endl;
		     my_list.push_back(word);
      		     r=i+1;
    		}
		else {
			for (sep = 0; sep < nb_separator; sep++) {
				if(line[i]== specialList[sep]) {
				     Lexeme word(line.substr(r, i-r));
				     word.avoidSpace();
				     //cout << "MOT : "  << word.getName() << endl;
				     my_list.push_back(word);
				     
				     Lexeme separator(line[i]);
				     //cout << "SEP : " << separator.getName() << endl;
				     my_list.push_back(separator);
				     r=i+1;
		      		     
		    		}
			}
		}  	
	}
Lexeme fin(line.substr(r, size-r));
my_list.push_back(fin);
return my_list;
}

