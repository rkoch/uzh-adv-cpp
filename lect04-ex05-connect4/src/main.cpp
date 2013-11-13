/*
 * main.cpp
 *
 *  Created on: 13.11.2013
 *      Author: rko
 */

#include <iostream>

#include "playfield.h"
#include "player.cpp"
#include "game.cpp"

int main(int argc, const char * argv[]) {
	player<playfield> p1;
	player<playfield> p2;
	playfield field;

	game<player<playfield>, player<playfield> > g(p1, p2);
	g.run(field);

	return 0;
}

