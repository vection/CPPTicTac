
#include "TicTacToe.h"

#define uint unsigned int

void TicTacToe::play(Player xPlayer,Player oPlayer) {
	
	xPlayer.myChar = 'X';
	oPlayer.myChar = 'O';
	bool gameover = false;
	while (!gameover) {
		turnX(xPlayer);
		if (check_winner(xPlayer.myChar)) { win = xPlayer; gameover = true; }
		turnY(oPlayer);
		if (check_winner(oPlayer.myChar)) { win = oPlayer; gameover = true; }
	}
}

bool TicTacToe::check_winner(char c) {
	if (check_rows(c) || check_angle(c) || check_colums(c)) { return true; }
	else { return false; }
}

bool TicTacToe::check_rows(char c) {
	int counter = 0;
	Coordinate p{0, 0};
	for (uint i = 0; i < game.size(); i++) {
		p.setx(i);
		for (uint j = 0; i < game.size(); j++) {
			p.sety(j);
			if (game[p] == c) { counter++; }
			else { counter = 0; }
		}
		if (counter == game.size()) { return true; }
	}
	return false;
}
bool TicTacToe::check_colums(char c) {
	int counter = 0;
	Coordinate p{ 0, 0 };
	for (uint i = 0; i < game.size(); i++) {
		p.sety(i);
		for (uint j = 0; i < game.size(); j++) {
			p.setx(j);
			if (game[p] == c) { counter++; }
			else { counter = 0; }
		}
		if (counter == game.size()) { return true; }
	}
	return false;
}

bool TicTacToe::check_angle(char c) {
	int counter = 0;
	bool win = false;
	Coordinate p{ 0, 0 };
	for (uint i = 0; i < game.size(); i++) {
		p.setx(i);
		p.sety(i);
		if (game[p] == c) { counter++; }
		if (counter == game.size()) { win = true; }
	}
	for (uint i = game.size(); i >= 0; i--) {
		p.setx(i);
		p.sety(i);
		if (game[p] == c) { counter++; }
		if (counter == game.size()) { win = true; }
	}
	return win;

}

void TicTacToe::turnX(Player xPlayer) {
	Coordinate p = xPlayer.play(game);
	game[p] = xPlayer.myChar;
}

void TicTacToe::turnY(Player oPlayer) {
	Coordinate p = oPlayer.play(game);
	game[p] = oPlayer.myChar;
}