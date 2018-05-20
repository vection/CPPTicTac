

#include <iostream>
#include <string>
using namespace std;


class IllegalCoordinateException : public exception {

public:
	int a, b;

	IllegalCoordinateException(int x, int y) {
		a = x;
		b = y;
	} 

	virtual const char* theCoordinate() const throw()
	{
		return (a + "," + b);
	}

};

