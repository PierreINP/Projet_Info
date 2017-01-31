//List of syntaxes to class lexemes into correct type
//Still to fill

#define N 50
#include <string>

using namespace std;

string keywordList[N] = {
	"library",
	"use",
	"all",	
	"entity",
	"is",
	"port",
	"in",
	"out",
	"downto",
	"upto",
	"end",
 	"architecture",
	"declaration",
	"of",
	"signal",
	"variable",
	"begin",
	"process",
	"case",
	"when",
	"others",
	"if",
	"then",
	"else",
	"elsif"	
};

char specialList[N] = {
	".;,:()\"'[]"	
};

string operatorList[N] = {
	"=>",
	"<=",
        ">",
	"<",
	"=",
	"==",
	"and",
	//"or",
	"not",
	"xor",
	"+",
	"*",
	"-",
	"/",
	"**",
	"&"
};
