#include"./../Header/Error.h"

using namespace std; 


	Error::Error() {log.open("./../../Log/Compileur.log");}
	
	
	void Error::generateLog(string code) {
		if (m_errors.size() != 0) {m_errors += "\n" +code;}
		else {m_errors += code;}		
		 
	}
	
	void Error::display() {
		cout << m_errors << endl;
	}
	 
	ostream& operator<<(ostream& out, const Error &e) {
			out << e.m_errors << endl;
	return out;
	}
