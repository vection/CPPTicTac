#pragma once

#include <iostream>
#include <string>
#include <utility>
#include "Coordinate.h"
#include "Board.h"
using namespace std;
class Player {

private:
	//string player_name;

public:
	char myChar;
	virtual const string  name() const {
		return "Player";
	}
	virtual const Coordinate play(const Board& board)=0;
    const char getChar() const { return myChar; }
   
};