#include"./../Header/Error.h"

using namespace std; 


	Error::Error() {
		ifstream file_errors("../Error_map.conf", ios::in);
	}
	
	
	void Error::generateLog(string code, int line, string name_lexeme) {
		if (m_errors.size() != 0) {m_errors += "\n" +code;}
		else {m_errors += code;}		
		 
	}
	
	void Error::display() {
		//Input Stream from file named sourcecode 
		
		string line; //line red in the file
		if (file_errors) {	
			while (getline(file_errors, line)) // reads the line
	    		{	
				cout << line << endl;
			}
		}
	}
	
	void Error::getErrors() const {

	} 

	ostream& operator<<(ostream& out, const Error &e) {
			out << e.m_errors << e.m_display << endl;
	return out;
	}
