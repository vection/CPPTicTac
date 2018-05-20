
#include <iostream>
#include <string>
#include <utility>     
#include "IllegalCharException.cpp"

using namespace std;


class Cell {

public:
	char* x;


	Cell(char* d) {
		x = d;
	}

	const char& operator = (char c) {
		if (c == 'O' || c == 'X') {

			*x = c;
		}
		else { throw IllegalCharException(c); }
		return c;
	}

	operator char() const { return *x; }


	friend ostream &operator<<(ostream &output, const Cell &temp) {
		output << temp.x;
		return output;
	}
};