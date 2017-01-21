#include"./../Header/Error.h"

using namespace std; 


	Error::Error() {}
	
	
	void Error::generateLog(string code, int line, string name_lexeme) {
		if (m_errors.size() != 0) {m_errors += "\n" +code;}
		else {m_errors += code;}		
		 
	}
	
	void Error::display() {
		cout << m_errors;
	}
	 

	ostream& operator<<(ostream& out, const Error &e) {
			out << e.m_errors << endl;
	return out;
	}
