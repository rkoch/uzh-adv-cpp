/*
 * playfield.h
 *
 *  Created on: 08.01.2014
 *      Author: rko
 */

#include <iostream>
#include "game.h"

using std::cout;
using std::endl;

template<typename P1, typename P2>
game<P1, P2>::game(P1 &p1, P2 &p2)
		: player1(p1), player2(p2) {
}

template<typename P1, typename P2>
void game<P1, P2>::run(ext_playfield &field) {
	cout << "Starting game..." << "\n" << endl;

	int winner = 0;
	while (true) {
		// Player 1
		cout << "Turn: Player 1" << endl;
		bool inserted = false;
		while (!inserted) {
			int col = player1.play(field);
			inserted = field.insert_stone(playfield::player1, col);
			if (!inserted) {
				cout << "This slot is already full - choose another one" << endl;
			}
		}

		// check if there is a winner
		if (field.winning(playfield::player1)) {
			winner = 1;
			break;
		}

		// check if field is full
		if (field.filled()) {
			break;
		}

		cout << "Playfield after Player 1's turn:" << endl;
		field.draw();
		cout << endl;

		// Player 2
		cout << "Turn: Player 2" << endl;
		inserted = false;
		while (!inserted) {
			int col = player2.play(field);
			inserted = field.insert_stone(playfield::player2, col);
			if (!inserted) {
				cout << "This slot cannot be assigned - choose another one" << endl;
			}
		}

		// check if there is a winner
		if (field.winning(playfield::player2)) {
			winner = 2;
			break;
		}

		// check if field is full
		if (field.filled()) {
			break;
		}

		cout << "Playfield after Player 2's turn:" << endl;
		field.draw();
		cout << endl;
	}

	cout << "---- ---- ---- ----  ---- ---- ---- ----" << "\n";
	if (winner != 0) {
		cout << "---- Player " << winner << " wins. Congratulations ----" << "\n";
	} else {
		// otherwise it has ended in a draw
		cout << "----   Game has ended in a draw.    ----" << "\n";
	}
	cout << "---- ---- ---- ----  ---- ---- ---- ----" << "\n" << endl;
	cout << "Ending field state:" << endl;
	field.draw();
}
