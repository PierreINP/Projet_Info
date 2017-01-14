/*
This programm is here to perform some functions. It must identify the lexemes, compute them to validate their conformity and then give them a type. 
Definitions of functions
*/
#ifndef _Lexeur_H_
#define _Lexeur_H_

#include "./../Header/Lexeme.h"

#include <stdlib.h>
#include <stdio.h>
#include <list> 
#include <iostream>
#include <string.h>
#include <fstream>

#define max_line_lenght 100
#define max_word_lenght 20

using namespace std;

list<Lexeme> readSource(char* file);
list<Lexeme> split_line(string line);

#endif
