/*
 * ext_playfield.cpp
 *
 *  Created on: 08.01.2014
 *      Author: rko
 */

#include "ext_playfield.h"

using std::cout;
using std::endl;
using std::vector;

ext_playfield::ext_playfield() {
	ext_playfield::clear();
}

ext_playfield::ext_playfield(const playfield &field) {
	ext_playfield::clear();

	// fill field
	for (int x = 0; x < playfield::width; x++) {
		for (int y = 0; y < playfield::height; y++) {
			rep[x][y] = field.stoneat(x, y);
		}
	}
}

ext_playfield::~ext_playfield() {
	// nothing to do (rule of three not fulfilled)
}

int ext_playfield::stoneat(int x, int y) const {
	return rep[x][y];
}

void ext_playfield::draw() {
	cout << "| ";
	for (int i = 0; i < ext_playfield::width; i++) {
		cout << "- ";
	}
	cout << "|" << "\n";

	for (int y = 0; y < ext_playfield::height; y++) {
		// each row
		cout << "| ";
		for (int x = 0; x < ext_playfield::width; x++) {
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
	for (int i = 0; i < ext_playfield::width; i++) {
		cout << "- ";
	}
	cout << "|" << "\n";

	cout << "| ";
	for (int i = 0; i < ext_playfield::width; i++) {
		cout << i << " ";
	}
	cout << "|" << endl;          // endline + flush
}

bool ext_playfield::insert_stone(int player, int col) {
	// range check
	if (col >= ext_playfield::width) {
//		perror("Entered column is not on the playfield.");
		return false;
	}

	// check wether the col is already full
	if (filled(col)) {
//		perror("Column is already filled.");
		return false;
	}

	// insert
	for (int y = ext_playfield::height - 1; y >= 0; y--) {
		if (rep[col][y] == 0) {
			rep[col][y] = player;
			break;
		}
	}

	return true;
}

bool ext_playfield::winning(int player) {

	// check horizontal winner
	for (int y = 0; y < ext_playfield::height; y++) {
		int consecutive_stones = 0;
		for (int x = 0; x < ext_playfield::width; x++) {
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
	for (int x = 0; x < ext_playfield::width; x++) {
		int consecutive_stones = 0;
		for (int y = 0; y < ext_playfield::height; y++) {
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
	for (int x = 0; x < ext_playfield::width; x++) {
		for (int y = 0; y < ext_playfield::height; y++) {
			// top-left to bottom-right
			if ((x + 3 < ext_playfield::width) && (y + 3 < ext_playfield::height)) {
				if ((rep[x][y] == player) && (rep[x + 1][y + 1] == player) && (rep[x + 2][y + 2] == player) && (rep[x + 3][y + 3] == player)) {
					return true;
				}
			}
			// bottom-left to top-right
			if ((x + 3 < ext_playfield::width) && (y - 3 >= 0)) {
				if ((rep[x][y] == player) && (rep[x + 1][y - 1] == player) && (rep[x + 2][y - 2] == player) && (rep[x + 3][y - 3] == player)) {
					return true;
				}
			}
		}
	}

	return false;
}

void ext_playfield::clear() {
	// initalize the field with zero's
	vector<int> vec;
	vec.assign(ext_playfield::height, ext_playfield::none);
	rep.assign(ext_playfield::width, vec);
}

bool ext_playfield::filled() {
	for (int x = 0; x < ext_playfield::width; x++) {
		if (rep[x][0] == 0) {
			return false;
		}
	}
	return true;
}

bool ext_playfield::filled(int col) {
	return rep[col][0] != 0;
}
