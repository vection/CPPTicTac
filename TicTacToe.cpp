
#include "TicTacToe.h"

#define uint unsigned int

void TicTacToe::play(Player& xPlayer,Player& oPlayer) {
	game.clean();	
	xPlayer.myChar = 'X';
	oPlayer.myChar = 'O';
	bool gameover = false;
	while (!gameover) {
		try {
			turnX(xPlayer);
		}
		catch (...) {
			win = &oPlayer;
			gameover = true;
			break;
		}
		if (check_winner(xPlayer.myChar)) { 
			win = &xPlayer; 
			gameover = true; 
			break;
		}
		else if (tie_check()) { win = &oPlayer; gameover = true; break; }
		try {
			turnY(oPlayer);
		}
		catch (...) {
			win = &xPlayer;
			gameover = true;
		}
		if (check_winner(oPlayer.myChar)) { 
			win = &oPlayer; 
			gameover = true;
		}
		else if (tie_check()) { win = &oPlayer; gameover = true; break; }
	}
}

bool TicTacToe::check_winner(char c) {
	if (check_rows(c) || check_angle(c) || check_colums(c)) {
		return true;
	}
	else { return false; }
}

bool TicTacToe::check_rows(char c) {
	int counter = 0;
	Coordinate t{ 0,0 };
	for (uint i = 0; i < game.size(); i++) {
		for (uint j = 0; j < game.size(); j++) {
			t.setx(i);
			t.sety(j);
			if (game[t]==c) { counter++; }
			else { counter = 0; }
		}
		if (counter == game.size()) { return true; }
	}
	return false;
}
bool TicTacToe::check_colums(char c) {
	int counter = 0;
	Coordinate t{ 0,0 };
	for (uint i = 0; i < game.size(); i++) {
		for (uint j = 0; j < game.size(); j++) {
			t.setx(j);
			t.sety(i);
			if (game[t] == c) { counter++; }
			else { counter = 0; }
		}
		if (counter == game.size()) { return true; }
	}
	return false;
}

bool TicTacToe::check_angle(char c) {
	int counter = 0;
	bool win = false;
	Coordinate t{ 0,0 };
	for (uint i = 0; i < game.size(); i++) {
		t.setx(i);
		t.sety(i);
		if (game[t] == c) { counter++; }
		if (counter == game.size()) { win = true; }
	}
	int mysize = game.size()-1;
	for (uint i = 0; i < game.size(); i++) {
		t.setx(i);
		t.sety(mysize);
		if(game[t] == c) { counter++; }
		if (counter == game.size()) { win = true; }
		mysize--;
	}
	return win;

}

void TicTacToe::turnX(Player& xPlayer) {
	Coordinate p = xPlayer.play(game);
	if (game[p] == '.') {
		game[p] = xPlayer.myChar;
	}
	else {
		throw "Illegal Move";
	}
}

void TicTacToe::turnY(Player& oPlayer) {
	Coordinate p = oPlayer.play(game);
	if (game[p] == '.') {
		game[p] = oPlayer.myChar;
	}
	else { throw "Illegal Move"; }
}

bool TicTacToe::tie_check() {
	int counter = 0;
	Coordinate t{ 0,0 };
	for (uint i = 0; i < game.size(); i++) {
		for (uint j = 0; j < game.size(); j++) {
			t.setx(i);
			t.sety(j);
			if (game[t] == '.') {
				return false;
			}
		}
	}
	return true;
}