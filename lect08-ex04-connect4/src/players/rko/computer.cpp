/*
 * computer.h
 *
 *  Created on: 13.11.2013
 *      Author: rko
 */

#include "computer.h"
#include "../../ext_playfield.h"

using std::cin;
using std::cout;
using std::endl;

int computer_player::play(const playfield &field) {
	// That was playfield::player1 but the linker could not find those symbols? Strange C++!!
	ext_playfield ext_field(field);
	int player_number = find_player_number(field);
	int enemy = (player_number == 1 ? 2 : 1);

	// Check if computer could win
	for (int x = 0; x < playfield::width; x++) {
		for (int y = 0; y < playfield::height; y++) {

			// Check  horizontal
			if ((x + 2 < playfield::width) && (ext_field.stoneat(x, y) == player_number) && (ext_field.stoneat(x + 1, y) == player_number) && (ext_field.stoneat(x + 2, y) == player_number)) {
				if ((x + 3 < playfield::width) && (ext_field.stoneat(x + 3, y) == 0) && ((y == playfield::height - 1) || (ext_field.stoneat(x + 3, y - 1) != 0))) {
					return x + 3;
				}

				if ((x > 0) && (ext_field.stoneat(x - 1, y) == 0) && ((y == playfield::height - 1) || (ext_field.stoneat(x - 1, y - 1) != 0))) {
					return x - 1;
				}
			}

			// Check vertical
			if ((y + 2 < playfield::height) && (ext_field.stoneat(x, y) == player_number) && (ext_field.stoneat(x, y + 1) == player_number) && (ext_field.stoneat(x, y + 2) == player_number)) {
				if ((y > 0) && (ext_field.stoneat(x, y - 1) == 0)) {
					return x;
				}
			}

			// Check diagonal (top-left to bottom-right)
			if ((x + 2 < playfield::width) && (y + 2 < playfield::height) && (ext_field.stoneat(x, y) == player_number) && (ext_field.stoneat(x + 1, y + 1) == player_number)
					&& (ext_field.stoneat(x + 2, y + 2) == player_number)) {
				if ((x + 3 < playfield::width) && (y + 3 < playfield::width) && (ext_field.stoneat(x + 3, y + 3) == 0)
						&& ((y + 3 == playfield::height - 1) || (ext_field.stoneat(x + 3, y + 4) != 0))) {
					return x + 3;
				}

				if ((x > 0) && (y > 0) && (ext_field.stoneat(x - 1, y - 1) == 0) && (ext_field.stoneat(x - 1, y) != 0)) {
					return x - 1;
				}
			}

			// Check diagonal (bottom-left to top-right)
			if ((x + 2 < playfield::width) && (y - 2 >= 0) && (ext_field.stoneat(x, y) == player_number) && (ext_field.stoneat(x + 1, y - 1) == player_number)
					&& (ext_field.stoneat(x + 2, y - 2) == player_number)) {
				if ((x + 3 < playfield::width) && (y - 3 >= 0) && (ext_field.stoneat(x + 3, y - 3) == 0) && (ext_field.stoneat(x + 3, y - 2) != 0)) {
					return x + 3;
				}

				if ((x > 0) && (y < playfield::height - 1) && (ext_field.stoneat(x - 1, y + 1) == 0) && ((y + 2 == playfield::height) || (ext_field.stoneat(x - 1, y + 2) != 0))) {
					return x - 1;
				}
			}
		}
	}

	// Check if enemy has 2 or more stones next to each other -> haunt him
	for (int x = 0; x < playfield::width; x++) {
		for (int y = 0; y < playfield::height; y++) {

			// Check horizontal
			if ((x + 1 < playfield::width) && (ext_field.stoneat(x, y) == enemy) && (ext_field.stoneat(x + 1, y) == enemy)) {
				if ((x + 2 < playfield::width) && (ext_field.stoneat(x + 2, y) == 0) && ((y == playfield::height - 1) || (ext_field.stoneat(x + 2, y - 1) != 0))) {
					return x + 2;
				}

				if ((x > 0) && (ext_field.stoneat(x - 1, y) == 0) && ((y == playfield::height - 1) || (ext_field.stoneat(x - 1, y - 1) != 0))) {
					return x - 1;
				}
			}

			// Check vertical
			if ((y + 1 < playfield::height) && (ext_field.stoneat(x, y) == enemy) && (ext_field.stoneat(x, y + 1) == enemy)) {
				if ((y > 0) && ext_field.stoneat(x, y - 1) == 0) {
					return x;
				}
			}

			// Check diagonal (top-left to bottom-right)
			if ((x + 1 < playfield::width) && (y + 1 < playfield::height) && (ext_field.stoneat(x, y) == enemy) && (ext_field.stoneat(x + 1, y + 1) == enemy)) {
				if ((x + 2 < playfield::width) && (y + 2 < playfield::height) && (ext_field.stoneat(x + 2, y + 2) == 0)
						&& ((y + 3 == playfield::height - 1) || (ext_field.stoneat(x + 2, y + 3) != 0))) {
					return x + 2;
				}

				if ((x > 0) && (y > 0) && (ext_field.stoneat(x - 1, y - 1) == 0) && (ext_field.stoneat(x - 1, y) != 0)) {
					return x - 1;
				}
			}

			// Check diagonal (bottom-left to top-right)
			if ((x + 1 < playfield::width) && (y - 1 >= 0) && (ext_field.stoneat(x, y) == enemy) && (ext_field.stoneat(x + 1, y - 1) == enemy)) {
				if ((x + 2 < playfield::width) && (y - 2 >= 0) && (ext_field.stoneat(x + 2, y - 2) == 0) && (ext_field.stoneat(x + 2, y - 1) != 0)) {
					return x + 2;
				}

				if ((x > 0) && (y < playfield::height - 1) && (ext_field.stoneat(x - 1, y + 1) == 0) && ((y + 2 == playfield::height) || (ext_field.stoneat(x - 1, y + 2) != 0))) {
					return x - 1;
				}
			}
		}
	}

	// Default behavior: return a random stone
	return rand() % playfield::width;
}

int computer_player::find_player_number(const playfield &field) {
	int p1 = 0, p2 = 0;

	for (int x = 0; x < playfield::width; x++) {
		for (int y = 0; y < playfield::height; y++) {
			int stone = field.stoneat(x, y);
			if (stone == 1) {
				p1++;
			} else if (stone == 2) {
				p2++;
			}
		}
	}

	if (p1 == p2) {
		// players stones are evenly distributed, I am player 1
		return 1;
	} else {
		return 2;
	}
}
