#pragma once

#include <iostream>
#include <string>
#include <utility>
#include "Coordinate.h"
#include "Board.h"
using namespace std;

class Player {
public:
	char myChar;

	/*Player() {
		myChar = '.';
	}*/
	virtual const string name() const;
	virtual const Coordinate play(const Board&);
	virtual const char getChar() const { return myChar; }
	/*Player(string n) {
		name = n;
		myChar = '.';
	}
	
     virtual const string name() const {
		return name;
	 }

	virtual const Coordinate play(const Board& p)  {
	Coordinate  c{ 0,0 };
		return c;
		
	}*/

};