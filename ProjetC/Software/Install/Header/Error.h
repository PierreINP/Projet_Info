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
		ofstream log;
		string m_errors;
	public :

	Error();
	~Error() {
		this->display();
		log << m_errors;
		log.close();
		
	};
	
	void generateLog(string code);
	void display();
	friend ostream& operator<<(ostream& out, const Error &e);

};

#endif
