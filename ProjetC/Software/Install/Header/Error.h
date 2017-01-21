#ifndef _ERROR_H_
#define _ERROR_H_

#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>

#include <fstream>
#include <iostream>

using namespace std; 

class Error {
	private :
		string m_errors;
	public :

	Error();
	
	void generateLog(string code, int line, string name_lexeme);
	void display();
	friend ostream& operator<<(ostream& out, const Error &e);

};

#endif
