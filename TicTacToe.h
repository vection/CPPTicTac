#pragma once
#include <string>
#include <iostream>
#include "Player.h"


class TicTacToe {
public:
	Board game;
	Player* win ;

	void play(Player& one, Player& two);
	bool check_winner(char c);
	bool check_rows(char c);
	bool check_colums(char c);
	bool check_angle(char c);
	void turnX(Player& x);
	void turnY(Player& y);
	TicTacToe(int num) {
		Board myboard(num);
		game = myboard;
	}

	const Player& winner() const { 
		return *win; 
	}
	Board board() const { return game; }


};
