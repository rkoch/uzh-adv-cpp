///*
// * Heuristics.h
// *
// *  Created on: 18.12.2013
// *      Author: CT
// */
//
#ifndef CT_HEURISTICS_H_
#define CT_HEURISTICS_H_
//
//#include "MyPlayfield.h"
//#include "MiniMaxPlayer.h"
//#include <vector>
//#include <limits>
//#include <iostream>
//#include <cmath>
//#include <algorithm>
//#include <iostream>
//
//class Heuristics {
//
//public:
//	float strength;
//
//	float ParalellizeMove(MyPlayfield& p, int Move) {
//		float value = 0;
//		for (int i = 0; i < strength; ++i) {
//			MyPlayfield tempBoard(p);
//			tempBoard.PutStone(Move);
//			int winner = Playout(tempBoard);
//			if (winner == p.myPlayer)
//				value++;
//			else if (winner == p.otherPlayer)
//				value--;
//		}
//		float result = value / strength;
//		return result;
//	}
//
//	int Playout(MyPlayfield& p) {
//		int randMove;
//		while (!p.Victory()) {
//			std::vector<int>* posMoves = p.GetMoves();
//			randMove = rand() % posMoves->size();
//			p.PutStone((*posMoves)[randMove]);
//			delete posMoves;
//		}
//		return p.Victory();
//	}
//};
//
#endif /* HEURISTICS_H_ */
