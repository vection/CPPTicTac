#include <iostream>
#include <string>
using namespace std;


class IllegalCharException : public exception {
public:

	char p;
	IllegalCharException(char a) {
		p = a;
	}
public:
	virtual const char* theChar() const throw()
	{
		return &p;
	}

};
