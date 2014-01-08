///*
// * players.cpp
// *
// *  Created on: 31.10.2013
// *  Author: Reto Wettstein
// * Advanced C++ Lecture 7 Exercise 3 + 4
// */
//
//#include <iostream>
//#include <stdlib.h>
//#include <vector>
//#include "if/player.h"
//#include "if/playfield.h"
//
//retos_computerplayer::retos_computerplayer(int representation)
//{
//	my_representation = representation;
//	if(representation == playfield::player1)
//	{
//		oponent_representation = playfield::player2;
//	}
//	else
//	{
//		oponent_representation = playfield::player1;
//	}
//}
//
//retos_computerplayer::retos_computerplayer(const retos_computerplayer& cp)
//{
//	my_representation = cp.my_representation;
//	oponent_representation = cp.oponent_representation;
//}
//
//retos_computerplayer::~retos_computerplayer()
//{
//
//}
//
//int retos_computerplayer::play(const playfield &field)
//{
//	for(int i = 1; i < playfield::width + 1; ++i)
//	{
//		copyboard(field);
//		updatecopyboard(i, my_representation);
//		if(checkwinning(my_representation))
//		{
//			return i-1;
//		}
//	}
//
//	for(int i = 1; i < playfield::width + 1; ++i)
//	{
//		copyboard(field);
//		updatecopyboard(i, oponent_representation);
//		if(checkwinning(oponent_representation))
//		{
//			return i-1;
//		}
//	}
//
//	return rand() % 7;
//}
//
//bool retos_computerplayer::updatecopyboard(int column, int playerrepresentation)
//{
//	int i = playfield::height - 1;
//	while(boardcopy[i][column - 1] != playfield::none)
//	{
//		--i;
//
//		if(i < 0)
//		{
//			return false;
//		}
//	}
//
//	boardcopy[i][column - 1] = playerrepresentation;
//	return true;
//
//}
//
//void retos_computerplayer::copyboard(const playfield &field)
//{
//	for(int i = 0; i < playfield::height; ++i)
//	{
//		for(int j = 0; j < playfield::width;  ++j)
//		{
//			boardcopy[i][j] = field.stoneat(j,i);
//		}
//	}
//}
//
//bool retos_computerplayer::checkwinning(int playerrepresentation)
//{
//	//check vertical
//	for(int i = 0; i < playfield::width; ++i)
//	{
//		for(int j = playfield::height - 1; j > 2 ; --j)
//		{
//			if(boardcopy[j][i] == playerrepresentation && boardcopy[j -1][i] == playerrepresentation && boardcopy[j - 2][i] == playerrepresentation && boardcopy[j - 3][i] == playerrepresentation)
//			{
//				return true;
//			}
//		}
//	}
//
//	//check horizontal
//	for(int i = playfield::height - 1; i >= 0; --i)
//	{
//		for(int j = 0; j < playfield::width - 3; ++j)
//		{
//			if(boardcopy[i][j] == playerrepresentation && boardcopy[i][j + 1] == playerrepresentation && boardcopy[i][j + 2] == playerrepresentation && boardcopy[i][j + 3] == playerrepresentation)
//			{
//				return true;
//			}
//		}
//	}
//
//	//check diagonal from bottom to top
//	for(int i = playfield::height - 1; i > 2; --i)
//	{
//		for(int j = 0; j < playfield::width - 3; ++j)
//		{
//			if(boardcopy[i][j] == playerrepresentation && boardcopy[i - 1][j + 1] == playerrepresentation && boardcopy[i - 2][j + 2] == playerrepresentation && boardcopy[i - 3][j + 3] == playerrepresentation)
//			{
//				return true;
//			}
//		}
//	}
//
//	//check diagonal from top to bottom
//	for(int i = 0; i < playfield::height - 3; ++i)
//	{
//		for(int j = 0; j < playfield::width - 3; ++j)
//		{
//			if(boardcopy[i][j] == playerrepresentation && boardcopy[i + 1][j + 1] == playerrepresentation && boardcopy[i + 2][j + 2] == playerrepresentation && boardcopy[i + 3][j + 3] == playerrepresentation)
//			{
//				return true;
//			}
//		}
//	}
//
//	return false;
//}
