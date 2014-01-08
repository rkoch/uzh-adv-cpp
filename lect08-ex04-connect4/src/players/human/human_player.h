/*
 * player.h
 *
 *  Created on: 13.11.2013
 *      Author: rko
 */

#ifndef HUMAN_PLAYER_H_
#define HUMAN_PLAYER_H_

#include "../../if/player.h"

class human_player: public player {

public:
	virtual int play(const playfield &field);
};

#endif
