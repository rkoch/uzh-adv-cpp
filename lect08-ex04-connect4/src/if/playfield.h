/*
 * playfield.h
 *
 *  Created on: 08.01.2014
 *      Author: rko
 */

#ifndef IF_PLAYFIELD_H_
#define IF_PLAYFIELD_H_

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

	// return the stone (none/player1/player2) at the position(x,y)
	// 0 <= x <= width
	// 0 <= y <= height
	// stoneat(0,0) ................ top left
	// stoneat(width-1,height-1) ... bottom right
	// if we insert a stone in a new game in column i,
	// it lands at (i,height-1)
	// implementation may be changed, interface not
	virtual int stoneat(int x, int y) const = 0;

	virtual ~playfield() {
	}

};

#endif

