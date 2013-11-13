/*
 * main.cpp
 *
 *  Created on: 13.11.2013
 *      Author: rko
 */

#include <iostream>

#include "playfield.h"
#include "player.cpp"
#include "computer.cpp"
#include "game.cpp"

int main(int argc, const char * argv[]) {
	player<playfield> p1(1);
	computer<playfield> p2(2);
	playfield field;

	game<player<playfield>, computer<playfield> > g(p1, p2);
	g.run(field);

	return 0;
}

