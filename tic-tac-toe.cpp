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

    draw_game_board(plateau);
    
    return 0;
}
