/*
 * player.cpp
 *
 *  Created on: 13.11.2013
 *      Author: rko
 */

#include <iostream>
#include "player.h"

using std::cin;
using std::cout;
using std::endl;

template<typename F>
player<F>::player(int num)
		: player_number(num) {

}

template<typename F>
int player<F>::play(const F &field) {

	cout << "Enter the column where your next stone should be placed:" << endl;
	int col;
	cin >> col;

	return col;
}
