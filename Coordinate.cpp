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
	x = xx;
}
void Coordinate::sety(unsigned int yy) {
	y = yy;
}