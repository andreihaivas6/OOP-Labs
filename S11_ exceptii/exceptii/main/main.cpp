#include <iostream>
#include <exception>
#include <stdexcept>
//#include "Array.h"

using namespace std;

class myException : public exception
{
	virtual const char* what() const throw()
	{
		return "belire maxima\n";
	}
};

int main() 
{
	try {
		throw myException();
		//throw runtime_error("ai belit pla\n");
	}
	/*catch (runtime_error& e) {
		cout << e.what();
	}*/
	catch (exception& e) { // !!! f imp &
		cout << e.what();
	}

	return 0;
}

