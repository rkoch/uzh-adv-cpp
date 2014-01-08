/*
 * player.h
 *
 *  Created on: 08.01.2014
 *      Author: rko
 */

#ifndef IF_PLAYER_H_
#define IF_PLAYER_H_

#include "playfield.h"

class player {
public:

	virtual int play(const playfield &field) = 0;

	virtual ~player() {
	}

};

#endif
