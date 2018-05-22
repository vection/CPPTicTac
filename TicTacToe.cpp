
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
	if (check_rows(c)) { return true; }
	else { return false; }
}

bool TicTacToe::check_rows(char c) {
	int counter = 0;
	for (uint i = 0; i < game.size(); i++) {
		for (uint j = 0; j < game.size(); j++) {
			Coordinate temp{ i,j };
			cout << temp;
			if (game[temp]==c) { counter++; }
			else { counter = 0; }
		}
		if (counter == game.size()) { return true; }
	}
	cout << "rows";
	return false;
}
bool TicTacToe::check_colums(char c) {
	int counter = 0;
	for (uint i = 0; i < game.size(); i++) {
		for (uint j = 0; j < game.size(); j++) {
			Coordinate temp{ i,j };
			cout << temp;
			if (game[temp] == c) { counter++; }
			else { counter = 0; }
		}
		if (counter == game.size()) { return true; }
	}
	cout << "colums";
	return false;
}

bool TicTacToe::check_angle(char c) {
	int counter = 0;
	bool win = false;
	for (uint i = 0; i < game.size(); i++) {
		Coordinate temp{ i,i };
		cout << temp;
		if (game[temp] == c) { counter++; }
		if (counter == game.size()) { win = true; }
	}
	for (uint i = game.size(); i >= 0; i--) {
		Coordinate temp{ i,i };
		if (game[temp] == c) { counter++; }
		if (counter == game.size()) { win = true; }
	}
	cout << "angle";
	return win;

}

void TicTacToe::turnX(Player xPlayer) {
	Coordinate p = xPlayer.play(game);
	game[p] = xPlayer.myChar;
}

void TicTacToe::turnY(Player oPlayer) {
	Coordinate p = oPlayer.play(game);
	game[p] = oPlayer.myChar;
	cout << "Turn Y";
}