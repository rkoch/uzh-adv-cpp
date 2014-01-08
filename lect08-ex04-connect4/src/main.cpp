/*
 * main.cpp
 *
 *  Created on: 13.11.2013
 *      Author: rko
 */

#include <iostream>

#include "ext_playfield.h"
#include "players/human/human_player.cpp"
#include "players/rko/computer.cpp"
#include "game.cpp"

int main(int argc, const char * argv[]) {
	human_player p1;
	computer_player p2;
	ext_playfield field;

	game<human_player, computer_player> g(p1, p2);
	g.run(field);

	return 0;
}

