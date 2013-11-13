/*
 * playfield.h
 *
 *  Created on: 13.11.2013
 *      Author: rko
 */

#ifndef PLAYFIELD_H_
#define PLAYFIELD_H_

#include <iostream>
#include <vector>

using std::vector;

class playfield {
public:

	// the size of the field
	const static int width = 7;
	const static int height = 6;

	// these elements are used to indicate whether a given position
	// in the playing field is taken by a given player
	const static int none = 0;
	const static int player1 = 1;
	const static int player2 = 2;

	playfield();

	// return the stone (none/player1/player2) at the position(x,y)
	// 0 <= x <= width
	// 0 <= y <= height
	// stoneat(0,0) ................ top left
	// stoneat(width-1,height-1) ... bottom right
	// if we insert a stone in a new game in column i,
	// it lands at (i,height-1)
	// implementation may be changed, interface not
	int stoneat(int x, int y) const;

	// prints field to cout
	void draw();

	// inserts a stone for a player at a desired column
	bool insert_stone(int player, int col);

	// checks if player is winning
	bool winning(int player);

	// clear playfield
	void clear();

	// check if playfield is filled
	bool filled();

	// check if column is already filled
	bool filled(int col);

protected:

	// the internal representation of the field
	vector<vector<int> > rep;

};

#endif

