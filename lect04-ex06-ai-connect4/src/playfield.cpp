/*
 * playfield.cpp
 *
 *  Created on: 13.11.2013
 *      Author: rko
 */

#include "playfield.h"

using std::cout;
using std::endl;
using std::vector;

playfield::playfield() {
	playfield::clear();
}

int playfield::stoneat(int x, int y) const {
	return rep[x][y];
}

void playfield::draw() {
	cout << "| ";
	for (int i = 0; i < playfield::width; i++) {
		cout << "- ";
	}
	cout << "|" << "\n";

	for (int y = 0; y < playfield::height; y++) {
		// each row
		cout << "| ";
		for (int x = 0; x < playfield::width; x++) {
			// each col
			if (rep[x][y] == 0) {
				cout << "  ";
			} else {
				cout << rep[x][y] << " ";
			}
		}
		cout << "|" << "\n";
	}

	cout << "| ";
	for (int i = 0; i < playfield::width; i++) {
		cout << "- ";
	}
	cout << "|" << "\n";

	cout << "| ";
	for (int i = 0; i < playfield::width; i++) {
		cout << i << " ";
	}
	cout << "|" << endl;          // endline + flush
}

bool playfield::insert_stone(int player, int col) {
	// range check
	if (col >= playfield::width) {
//		perror("Entered column is not on the playfield.");
		return false;
	}

	// check wether the col is already full
	if (filled(col)) {
//		perror("Column is already filled.");
		return false;
	}

	// insert
	for (int y = playfield::height - 1; y >= 0; y--) {
		if (rep[col][y] == 0) {
			rep[col][y] = player;
			break;
		}
	}

	return true;
}

bool playfield::winning(int player) {

	// check horizontal winner
	for (int y = 0; y < playfield::height; y++) {
		int consecutive_stones = 0;
		for (int x = 0; x < playfield::width; x++) {
			if (rep[x][y] == player) {
				// increment and test at the same time
				if (++consecutive_stones >= 4) {
					return true;
				}
			} else {
				consecutive_stones = 0;
			}
		}
	}

	// Check vertical winner
	for (int x = 0; x < playfield::width; x++) {
		int consecutive_stones = 0;
		for (int y = 0; y < playfield::height; y++) {
			if (rep[x][y] == player) {
				// increment and test at the same time
				if (++consecutive_stones >= 4) {
					return true;
				}
			} else {
				consecutive_stones = 0;
			}
		}
	}

	// Check diagonal winner
	for (int x = 0; x < playfield::width; x++) {
		for (int y = 0; y < playfield::height; y++) {
			// top-left to bottom-right
			if ((x + 3 < playfield::width) && (y + 3 < playfield::height)) {
				if ((rep[x][y] == player) && (rep[x + 1][y + 1] == player) && (rep[x + 2][y + 2] == player) && (rep[x + 3][y + 3] == player)) {
					return true;
				}
			}
			// bottom-left to top-right
			if ((x + 3 < playfield::width) && (y - 3 >= 0)) {
				if ((rep[x][y] == player) && (rep[x + 1][y - 1] == player) && (rep[x + 2][y - 2] == player) && (rep[x + 3][y - 3] == player)) {
					return true;
				}
			}
		}
	}

	return false;
}

void playfield::clear() {
	// initalize the field with zero's
	vector<int> vec;
	vec.assign(playfield::height, playfield::none);
	rep.assign(playfield::width, vec);
}

bool playfield::filled() {
	for (int x = 0; x < playfield::width; x++) {
		if (rep[x][0] == 0) {
			return false;
		}
	}
	return true;
}

bool playfield::filled(int col) {
	return rep[col][0] != 0;
}
