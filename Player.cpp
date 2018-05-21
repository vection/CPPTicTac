#include <iostream>
#include <string>
#include "Player.h"
using namespace std;


const string Player::name() const {
	return player_name;
};

const Coordinate Player::play(const Board& board) {

	Coordinate c{ 0,0 };
	return c;
};