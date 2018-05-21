#pragma once

#include <iostream>
#include <string>
#include <utility>
#include "Coordinate.h"
#include "Board.h"
using namespace std;
class Player {

private:
	string player_name;

public:
	char myChar;
	virtual const string  name() const;
	virtual const Coordinate play(const Board& board);
    const char getChar() const { return myChar; }
   
};