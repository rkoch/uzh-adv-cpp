///*
// * cpu_player_daabae.h
// *
// *  Created on: 30.12.2013
// *      Author: Daniel
// */
//
#ifndef CPU_PLAYER_DAABAE_H_
#define CPU_PLAYER_DAABAE_H_
//
///*
// * my_player.h
// *
// *  Created on: 22.12.2013
// *      Author: Daniel
// */
//
//#include <vector>
//
//#include "player.h"
//#include "playfield.h"
//
//#ifndef DAABAE_PLAYFIELDCPU_H_
//#define DAABAE_PLAYFIELDCPU_H_
//
//
//class daabae_playfieldCPU: public playfield{
//public:
//	std::vector<std::vector<int> > board;
//
//	// 0<=x<=width-1, 0<=y<=height-1
//	virtual int stoneat(int x, int y) const{
//		return board[x][y];
//	}
//
//	virtual ~daabae_playfieldCPU() {}
//
//	inline void insert(int x, int y, int player){
//		board[x][y]=player;
//	}
//
//	daabae_playfieldCPU(){
//		std::vector<int> vec;
//		vec.assign(playfield::height, 0); // replaced playfield::none (wtf??) with 0
//		board.assign(playfield::width, vec);
//	}
//
//	inline void draw_board() const{
//		std::cout << std::endl;
//		std::cout << "  1 2 3 4 5 6 7 " << std::endl;
//		for(int i = 0; i < playfield::height; ++i){
//			std::cout << "| ";
//			for(int j = 0; j < playfield::width;  ++j){
//				if(stoneat(j, i) == playfield::player1){
//					std::cout << "x" <<  " ";
//				}else if(stoneat(j, i) == playfield::player2){
//					std::cout << "o" <<  " ";
//				}else if(stoneat(j,i)==0){
//					std::cout << " " << " ";
//				}else{
//					std::cout<<"ERROR: Playfield is corrupted!\n";
//				}
//			}
//			std::cout << "|" << std::endl;
//		}
//		std::cout << " --------------- " << std::endl;
//		std::cout << std::endl;
//	}
//
//	inline bool check_for_winner(int player) const{
//		//check vertical
//		for(int i = 0; i < playfield::width; ++i){
//			for(int j = playfield::height - 1; j > 2 ; --j){
//				if(stoneat(i,j) == player && stoneat(i,j-1) == player && stoneat(i,j - 2) == player && stoneat(i,j - 3) == player ){
//					return true;
//				}
//			}
//		}
//
//		//check horizontal
//		for(int i = playfield::height - 1; i > 2; --i){
//			for(int j = 0; j < playfield::width - 3; ++j){
//				if(stoneat(j,i) == player && stoneat(j+1,i) == player && stoneat(j+2,i) == player && stoneat(j+3,i) == player){
//					return true;
//				}
//			}
//		}
//
//		//check diagonal from bottom-left to top-right
//		for(int i = playfield::height - 1; i > 2; --i){
//			for(int j = 0; j < playfield::width - 3; ++j){
//				if(stoneat(j,i) == player && stoneat(j+1,i-1) == player && stoneat(j+2,i-2) == player && stoneat(j+3,i-3) == player){
//					return true;
//				}
//			}
//		}
//
//		//check diagonal from top-left to bottom-right
//		for(int i = 0; i < playfield::height - 3; ++i){
//			for(int j = 0; j < playfield::width - 3; ++j){
//				if(stoneat(j,i) == player && stoneat(j+1,i+1) == player && stoneat(j+2,i+2) == player && stoneat(j+3,i+3) == player){
//					return true;
//				}
//			}
//		}
//		return false;
//	}
//
//	inline bool is_board_full() const{
//		for(int i=0; i<playfield::width; ++i){
//			if(stoneat(i,0)==0){
//				return false;
//			}
//		}
//		return true;
//	}
//};
//#endif /* DAABAE_PLAYFIELDCPU_H_ */
//
//
//class cpu_player_daabae: public player {
//private:
//	int cpu;
//	int opponent;
//
//	int put(int column, int player, daabae_playfieldCPU &field);
//	void remove(int column, int row, daabae_playfieldCPU &field);
//	int check_winnable_for(daabae_playfieldCPU &field, int player);
//public:
//  virtual int play(const playfield &field);
//  virtual ~cpu_player_daabae() {}
//    cpu_player_daabae() {} // added by myself
//  cpu_player_daabae(int cpu, int opponent): cpu(cpu), opponent(opponent){};
//  int my_random(){
//  	return abs(random()+time(0)+rand());
//  }
//};
//
//
#endif /* CPU_PLAYER_DAABAE_H_ */
