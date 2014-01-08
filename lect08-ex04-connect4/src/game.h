/*
 * game.h
 *
 *  Created on: 08.01.2014
 *      Author: rko
 */

#ifndef GAME_H_
#define GAME_H_

#include "ext_playfield.h"

template<typename P1, typename P2>
class game {
public:

	game(P1 &p1, P2 &p2);

	void run(ext_playfield &field);

private:

	P1 player1;
	P2 player2;

};

#endif
