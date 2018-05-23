#pragma once
#include "Player.h"


using namespace std;
/**
*Constructor extend from Player
*/
class Champion : public Player {
public:
	const string name() const override { return "Aviv and Maor"; }
	const Coordinate play(const Board& board) override;

	
};