#pragma once
#include <iostream>
#include <string>
#include <utility>     
#include "IllegalCoordinateException.cpp"
#include "Cell.h"
#include "Coordinate.h"
using namespace std;

#define uint unsigned int

class Board {




public:
	char* mat;
	 int length;

	const unsigned int size() const;
	Board() {
		mat = new char[5];
		length = 5;
		for (int i = 0; i < length*length; i++) { mat[i] = '.'; }
	}
	 Board(int num) {
		length = (uint)num;
		mat = new char[(uint)num*num];
		for (int i = 0; i < length*length; i++) { mat[i] = '.'; }
	}

	Cell operator [] (Coordinate p) 
	{
		int x = p.first();
		int y = p.second();
		int a = returnsyntax(x, y);
		if (a >= (length*length)) { 
			throw IllegalCoordinateException(x, y); 
		}
		
		return Cell(&mat[a]);
		
	}
	const Cell operator [] (Coordinate p) const
	{
		int x = p.first();
		int y = p.second();
		int a = returnsyntax(x, y);
		if (a >= (length*length)) {
			throw IllegalCoordinateException(x, y);
		}

		return Cell(&mat[a]);

	}
	int returnsyntax(const int x, const int y) const {	
		return this->length*x + y;
		
	}

	 Board& operator = (char c) {
		if (c == 'O' || c == 'X') {

			return *this;
		}
		else if (c == '.') { 
			for (int i = 0; i < length*length; i++) {
				mat[i] = '.'; 
			} 
		}
		else { throw IllegalCharException(c); }
	}
	
	friend ostream &operator<<(ostream &output, const Board &temp) {
		string p = "";
		int counter = 0;
		for (int i = 0; i < temp.length*temp.length; i++) {
			p += temp.mat[i];
			counter++;
			if(counter == temp.length) {
				p += "\n";
				counter = 0;
			}
		}
		output << p;
		return output;
	}

	const void clean() const {
		for (int i = 0; i < length*length; i++) { mat[i] = '.'; }
	}
};