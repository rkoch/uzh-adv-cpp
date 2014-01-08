///*
// * CPU-player-09925009.cpp
// *
// *  Created on: 30.12.2013
// *      Author: Daniel
// */
//
//
//#include <set>
//
//#include "CPU_player_daabae.h"
//
//int cpu_player_daabae::put(int column, int player, daabae_playfieldCPU &field){
//	int i=playfield::height-1;
//	while(i>=0 && field.stoneat(column,i) != playfield::none){
//		--i;
//	}
//	if(i<0){
//		throw "ERROR: An error occurred!";
//	}
//	field.insert(column,i, player);
//	return i;
//}
//
//void cpu_player_daabae::remove(int column, int row, daabae_playfieldCPU &field){
//	field.insert(column, row, playfield::none);
//}
//
//int cpu_player_daabae::check_winnable_for(daabae_playfieldCPU &field, int player){
//	for(int i=0;i<playfield::width;++i){
//		if(field.stoneat(i, 0)!=playfield::none){
//			continue;
//		}
//		int row = put(i, player, field);
//		if(field.check_for_winner(player)){
//			return i+1;
//		}
//		remove(i,row, field);
//	}
//	return -1;
//}
//
//
//int cpu_player_daabae::play(const playfield &field){
//
//	// copy playfield in my_playfieldCPU
//	daabae_playfieldCPU my_field;
//	for(int i=0; i<playfield::width;++i){
//		for(int j=0; j<playfield::height;++j){
//			my_field.insert(i,j,field.stoneat(i,j));
//		}
//	}
//
//	// check if CPU can win
//	int column = check_winnable_for(my_field, cpu);
//	if(column > 0){
//		//std::cout<<"win\n";
//		return column-1;
//	}
//
//	// check if opponent can win
//	column = check_winnable_for(my_field, opponent);
//	if(column > 0){
//		//std::cout<<"deny\n";
//		return column-1;
//	}
//
//	// avoid inevitable losing situation
//	for(int j=playfield::height-1;j>=0;--j){
//		for(int i=0; i<playfield::width-4;++i){
//			// _,x,x,_,_
//			if((j==playfield::height-1) || (field.stoneat(i,j+1)!=playfield::none)){
//				if(field.stoneat(i,j)==playfield::none && field.stoneat(i+1,j)==opponent && field.stoneat(i+2,j)==opponent && field.stoneat(i+3,j)==playfield::none && field.stoneat(i+4,j)==playfield::none){
//
//					//check if opponent can win after random column
//					column = i;
//					bool loop = false;
//					while(true){
//						while(true){
//							int row1 = put(column, cpu, my_field);
//							if(row1==0){
//								loop = true;
//								break;
//							}else{
//								int row2 = put(column, opponent, my_field);
//								if(my_field.check_for_winner(opponent)){
//									remove(column, row1, my_field);
//									remove(column, row2, my_field);
//									loop = true;
//									break;
//								}else{
//									break;
//								}
//							}
//						}
//						if(loop){
//							if(((j==playfield::height-1) || (field.stoneat(i+3,j+1)!=playfield::none)) && column < i+3){
//								column = i+3;
//							}else if(((j==playfield::height-1) || (field.stoneat(i+4,j+1)!=playfield::none)) && column < i+4){
//								column = i+4;
//							}else{
//								break;
//							}
//						}else{
//							break;
//						}
//					}
//					//std::cout<<"_XX__\n";
//					return column;
//				}
//			}
//			// _,_,x,x,_
//			if((j==playfield::height-1) || (field.stoneat(i+1,j+1)!=playfield::none)){
//				if(field.stoneat(i,j)==playfield::none && field.stoneat(i+1,j)==playfield::none && field.stoneat(i+2,j)==opponent && field.stoneat(i+3,j)==opponent && field.stoneat(i+4,j)==playfield::none){
//
//					//check if opponent can win
//					column = i+4;
//					bool loop = false;
//					while(true){
//						while(true){
//							int row1 = put(column, cpu, my_field);
//							if(row1==0){
//								loop = true;
//								break;
//							}else{
//								int row2 = put(column, opponent, my_field);
//								if(my_field.check_for_winner(opponent)){
//									remove(column, row1, my_field);
//									remove(column, row2, my_field);
//									loop = true;
//									break;
//								}else{
//									break;
//								}
//							}
//						}
//						if(loop){
//							if(((j==playfield::height-1) || (field.stoneat(i+1,j+1)!=playfield::none)) && column > i+1){
//								column = i+1;
//							}else if(((j==playfield::height-1) || (field.stoneat(i+4,j+1)!=playfield::none)) && column > i){
//								column = i;
//							}else{
//								break;
//							}
//						}else{
//							break;
//						}
//					}
//					//std::cout<<"__XX_\n";
//					return column;
//				}
//			}
//		}
//	}
//
//
//	// not losing column
//	std::set<int> full_columns;
//	std::set<int> losing_columns;
//	int counter = 0;
//	while(true){
//		++counter;
//		//get randomized column
//		int rand_col = (my_random() % playfield::width);
//		if(full_columns.find(rand_col)==full_columns.end() && losing_columns.find(rand_col)==losing_columns.end()){
//			column = rand_col;
//		}else{
//			continue;
//		}
//
//		//check if column full
//		if(field.stoneat(column, 0)!=playfield::none){
//			full_columns.insert(column);
//			continue;
//		}
//
//		//check if opponent can win after random column
//		int row1 = put(column, cpu, my_field);
//		if(row1==0){
//			break;
//		}else{
//			int row2 = put(column, opponent, my_field);
//			if(my_field.check_for_winner(opponent)){
//				losing_columns.insert(column);
//				remove(column, row1, my_field);
//				remove(column, row2, my_field);
//			}else{
//				break;
//			}
//		}
//		if(counter>2*playfield::width){
//			if(full_columns.size()==playfield::width){
//				throw "ERROR: Board is full! Game should have ended!\n";
//			}
//			if(losing_columns.empty()){
//				throw "ERROR: An error occurred!\n";
//			}else{
//				//std::cout<<"losing\n";
//				return *losing_columns.begin()+1;
//			}
//		}
//	}
//	//std::cout<<"random\n";
//	return column;
//}
