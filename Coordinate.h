#pragma once

#include <iostream>
#include <string>
#include <utility>   
#include <initializer_list>
using namespace std;

#define uint unsigned int

class Coordinate {


public:
	initializer_list<unsigned int> p;
	uint x;
	uint y;



	Coordinate(initializer_list<unsigned int> t) {
		x = *t.begin();
		y = *(t.begin() + 1);
	}
	unsigned int first();
	unsigned int second();
	void setx(unsigned int x);
	void sety(unsigned int y);
};