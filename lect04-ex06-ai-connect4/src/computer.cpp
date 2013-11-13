/*
 * computer.h
 *
 *  Created on: 13.11.2013
 *      Author: rko
 */

#include "computer.h"

using std::cin;
using std::cout;
using std::endl;

template<typename F>
int computer<F>::play(const F &field) {
	// That was playfield::player1 but the linker could not find those symbols? Strange C++!!
	int enemy = (player_number == 1 ? 2 : 1);

	// Check if enemy has 2 or more stones next to each other -> haunt him
	for (int x = 0; x < playfield::width; x++) {
		for (int y = 0; y < playfield::height; y++) {

			// Check horizontal
			if ((x + 1 < playfield::width) && (field.stoneat(x, y) == enemy) && (field.stoneat(x + 1, y) == enemy)) {
				if ((x + 2 < playfield::width) && (field.stoneat(x + 2, y) == 0) && ((y == playfield::height - 1) || (field.stoneat(x + 2, y - 1) != 0))) {
					return x + 2;
				}

				if ((x > 0) && (field.stoneat(x - 1, y) == 0) && ((y == playfield::height - 1) || (field.stoneat(x - 1, y - 1) != 0))) {
					return x - 1;
				}
			}

			// Check vertical
			if ((y + 1 < playfield::height) && (field.stoneat(x, y) == enemy) && (field.stoneat(x, y + 1) == enemy)) {
				if ((y > 0) && field.stoneat(x, y - 1) == 0) {
					return x;
				}
			}

			// Check diagonal (top-left to bottom-right)
			if ((x + 1 < playfield::width) && (y + 1 < playfield::height) && (field.stoneat(x, y) == enemy) && (field.stoneat(x + 1, y + 1) == enemy)) {
				if ((x + 2 < playfield::width) && (y + 2 < playfield::height) && (field.stoneat(x + 2, y + 2) == 0)
						&& ((y + 3 == playfield::height - 1) || (field.stoneat(x + 2, y + 3) != 0))) {
					return x + 2;
				}

				if ((x > 0) && (y > 0) && (field.stoneat(x - 1, y - 1) == 0) && (field.stoneat(x - 1, y) != 0)) {
					return x - 1;
				}
			}

			// Check diagonal (bottom-left to top-right)
			if ((x + 1 < playfield::width) && (y - 1 >= 0) && (field.stoneat(x, y) == enemy) && (field.stoneat(x + 1, y - 1) == enemy)) {
				if ((x + 2 < playfield::width) && (y - 2 >= 0) && (field.stoneat(x + 2, y - 2) == 0) && (field.stoneat(x + 2, y - 1) != 0)) {
					return x + 2;
				}

				if ((x > 0) && (y < playfield::height - 1) && (field.stoneat(x - 1, y - 1) == 0) && ((y - 2 < playfield::height) || (field.stoneat(x - 1, y - 2) != 0))) {
					return x - 1;
				}
			}
		}
	}

	// Otherwise place stone where computer could win
	for (int x = 0; x < playfield::width; x++) {
		for (int y = 0; y < playfield::height; y++) {

			// Check  horizontal

			// Check vertical

			// Check diagonal
		}
	}

	// Default return
	return rand() % playfield::width;
}
