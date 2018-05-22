#pragma once

#include <iostream>
#include <string>
#include <utility>   
#include <initializer_list>
using namespace std;

#define uint unsigned int

class Coordinate {


public:
	initializer_list<unsigned int> *p;
	uint x;
	uint y;



	Coordinate(initializer_list<unsigned int> t) {
		x = *t.begin();
		y = *(t.begin() + 1);
		p = &t;
		
	}
	unsigned int first();
	unsigned int second();
	void setx(unsigned int x);
	void sety(unsigned int y);

	friend ostream &operator<<(ostream &output, const Coordinate &temp) {
		string p = "{" + to_string(temp.x) + "," + to_string(temp.y) + "}";
		output << p;
		return output;
	}
};