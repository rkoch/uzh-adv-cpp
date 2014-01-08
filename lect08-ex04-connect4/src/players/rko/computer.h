/*
 * computer.h
 *
 *  Created on: 13.11.2013
 *      Author: rko
 */

#ifndef _COMPUTER_PLAYER_H_
#define _COMPUTER_PLAYER_H_

#include <iostream>
#include "../../if/player.h"

class computer_player: public player {

public:
	int play(const playfield &field);

private:
	int find_player_number(const playfield &field);

};

#endif /* COMPUTER_H_ */
