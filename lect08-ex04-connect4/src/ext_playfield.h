/*
 * ext_playfield.h
 *
 *  Created on: 08.01.2014
 *      Author: rko
 */

#ifndef EXT_PLAYFIELD_H_
#define EXT_PLAYFIELD_H_

#include <iostream>
#include <vector>

#include "if/playfield.h"

using std::vector;

class ext_playfield: public playfield {
public:

	ext_playfield();
	ext_playfield(const playfield &field);
	virtual ~ext_playfield();

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

