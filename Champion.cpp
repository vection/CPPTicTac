#include "Champion.h"

/**
*Strategy to win the other player
*/

const Coordinate Champion::play(const Board& board) {
	uint i = 0; 
	uint j = 0;
	uint bs = board.size() - 1;
	// Checking for the corners
	Coordinate c = { bs ,j };
	if (board[c] == '.')
		return c;
	c = { i,bs };
	if (board[c] == '.')
		return c;

	c = { i + 1, bs - 1 };
	if (board[c] == '.')
		return c;

	c = { bs - 1,j + 1 };
	if (board[c] == '.')
		return c;

	for (i = 1; i <= bs; i++) {
		c = { bs,i };
		if (board[c] == '.')
			return c;
	}

	for (i = 0; i <= bs; i++) {
		for (j = 0; j <= bs; j++) {
			c = { i,j };
			if (board[c] == '.')
				return c;
		}
	}

	return { 0,0 };
}



