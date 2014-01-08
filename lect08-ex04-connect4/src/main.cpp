/*
 * main.cpp
 *
 *  Created on: 13.11.2013
 *      Author: rko
 */

#include <iostream>

#include "ext_playfield.h"
#include "players/human/human_player.h"
#include "players/rko/computer.h"
#include "players/rma/ai.h"
#include "players/rwe/retos_computerplayer.h"
#include "game.cpp"

int main(int argc, const char * argv[]) {
	human_player p1;
	computer_player p2; // Remo Koch
	ai p3; // Raphael Matile
	retos_computerplayer p4; // Reto Wettstein


	ext_playfield field;

//	game<human_player, computer_player> g1(p1, p2);
//	g1.run(field);

//	game<computer_player, ai> g2(p2, p3);
//	g2.run(field);

	game<computer_player, retos_computerplayer> g3(p2, p4);
	g3.run(field);

	return 0;
}

