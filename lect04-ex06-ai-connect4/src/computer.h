/*
 * computer.h
 *
 *  Created on: 13.11.2013
 *      Author: rko
 */

#ifndef COMPUTER_H_
#define COMPUTER_H_

#include <iostream>
#include "player.h"
#include "playfield.h"

template<typename F>
class computer {

public:
	computer(int num)
			: player_number(num) {
	}

	int play(const F &field);

	int player_number;
};

#endif /* COMPUTER_H_ */
