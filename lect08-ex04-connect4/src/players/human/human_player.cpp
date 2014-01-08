/*
 * player.cpp
 *
 *  Created on: 13.11.2013
 *      Author: rko
 */

#include <iostream>
#include "human_player.h"

using std::cin;
using std::cout;
using std::endl;

int human_player::play(const playfield &field) {

	cout << "Enter the column where your next stone should be placed:" << endl;
	int col;
	cin >> col;

	return col;
}
