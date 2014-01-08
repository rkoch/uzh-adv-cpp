/*
 * players.h
 *
 *  Created on: 31.10.2013
 *  Author: Reto Wettstein
 *  Advanced C++ Lecture 7 Exercise 3 + 4
 */

#ifndef _RWE_PLAYER_H_
#define _RWE_PLAYER_H_

#include <string>
#include <vector>
#include "../../if/playfield.h"
#include "../../if/player.h"

class retos_computerplayer : public player
{
private:
	int boardcopy[7][6];
	int my_representation;
	int oponent_representation;

	bool checkwinning(int playerrepresentation);
	void copyboard(const playfield &field);
	bool updatecopyboard(int column, int playerrepresentation);
public:
    retos_computerplayer() {};
	retos_computerplayer(int representation);
	retos_computerplayer(const retos_computerplayer& cp);
	virtual ~retos_computerplayer();

	int play(const playfield &field);
};

#endif
