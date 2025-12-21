#include <iostream>
#include "board.hpp"

void draw_game_board(char board[][3]){
    for (int i{0}; i< 3; ++i){
        for (int j{0}; j<3; ++j){
            

            std::cout<<"| "<<board[i][j]<<" ";
    }
        std::cout<<"|"<<std::endl;

    }
    
}