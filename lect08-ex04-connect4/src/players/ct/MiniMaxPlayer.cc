///*
// * MiniMaxPlayer.cc
// *
// *  Created on: 18.12.2013
// *      Author: CT
// */
//
//#include "MiniMaxPlayer.h"
//#include "Heuristics.h"
//#include "MyPlayfield.h"
//#include "playfield.h"
//#include <vector>
//#include <limits>
//#include <iostream>
//#include <cmath>
//#include <algorithm>
//
//MiniMaxPlayer::MiniMaxPlayer(int t){
//	turn = t;
//}
//
//int MiniMaxPlayer::play(const playfield &field) {
//
//	MyPlayfield p(field);
//
//	p.myPlayer = turn;
//	p.myTurn = turn;
//	p.otherPlayer = (turn == 1) ? 2 : 1;
//
//	std::vector<int>* posMoves = p.GetMoves();
//
//	int colChosen = -1;
//	float initialRating = -1.0f * std::numeric_limits<float>::max();
//
//	for (int x : *posMoves)
//	{
//		std::cout << "Checking Move " << x + 1 << "..." << std::endl;
//		float eval = RateCol(p, x, 0);
//		std::cout << "Move rating: " << eval << std::endl;
//		if (eval > initialRating)
//				{
//			initialRating = eval;
//			colChosen = x;
//		}
//	}
//	std::cout << "Minimax plays column: " << colChosen + 1<< std::endl;
//	delete posMoves;
//	return colChosen;
//}
//
//float MiniMaxPlayer::RateCol(MyPlayfield &p, int Move, int deep) {
//	int gameState = p.Victory();
//	if (gameState) {
//		if (gameState == -1)
//			return 0.0f;
//		float end = (p.myTurn == p.otherPlayer) ? 1.0f : -1.0f;
//		return end;
//	}
//	if (deep >= MAX_DEEP) {
//		heuristics.strength = pow(7, strength);
//		float value = 0;
//		value = heuristics.ParalellizeMove(p, Move);
//		return value;
//	}
//
//	p.PutStone(Move);
//	std::vector<int>* posMoves = p.GetMoves();
//
//	float val = 0;
//
//	if (deep % 2 == 0)
//		val = -1.0f * std::numeric_limits<float>::max();
//	else
//		val = std::numeric_limits<float>::max();
//
//	for (int M : *posMoves) {
//		float rating = RateCol(p, M, deep + 1);
//		if (deep % 2 == 0)
//			val = std::max(val, rating);
//		else
//			val = std::min(val, rating);
//	}
//
//	p.RemoveStone(Move);
//	delete posMoves;
//	return val;
//}
//
