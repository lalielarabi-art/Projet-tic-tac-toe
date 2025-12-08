#include <iostream>
#include "Player.hpp"
#include "board.hpp"


int main() {
    Player player1 = create_player();
    Player player2 = create_player();
    
      

    char plateau[3][3]={
      {'1','2','3'},
      {'4','5','6'},
      {'7','8','9'}
    };
    
    int box {};
    
    draw_game_board(plateau);
    std::cout<<"Le joueur "<<player1.name<<" doit jouer."<<std::endl;
    std::cin >> box;
    int lign {(box-1)/3};
    int column {(box-1)%3};
    plateau[lign][column]=player1.symbol;
    draw_game_board(plateau);
    
    return 0;
}
