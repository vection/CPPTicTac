#include <iostream>
#include <string>
#include "Coordinate.h"
using namespace std;

Coordinate::Coordinate(initializer_list<unsigned int> tpp) {
	x = *tpp.begin();
	y = *(tpp.begin() + 1);
}

unsigned int Coordinate::first() {
	unsigned int s = *p.begin();
	return s;	
}

unsigned int Coordinate::second() {
	unsigned int s = *(p.begin() + 1);
	return s;
}

void Coordinate::setx(unsigned int xx) {
	x = xx;
}
void Coordinate::sety(unsigned int yy) {
	y = yy;
}