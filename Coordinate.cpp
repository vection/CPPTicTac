#include <iostream>
#include <string>
#include "Coordinate.h"
using namespace std;


unsigned int Coordinate::first() {
	return x;	
}

unsigned int Coordinate::second() {
	return y;
}

void Coordinate::setx(unsigned int xx) {
	initializer_list<unsigned int> temp ({ xx,y });
	p = &temp;
	x = xx;
}
void Coordinate::sety(unsigned int yy) {
	initializer_list<unsigned int> temp ({ x, yy });
	p = &temp;
	y = yy;
}