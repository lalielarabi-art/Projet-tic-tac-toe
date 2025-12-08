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
    
while (!sby_won(plateau)){
    turn(player1, plateau);

    if (sby_won(plateau)){
      std::cout<<"Le joueur "<<player1.name<<" a gagné!"<<std::endl;

      break;
    }

    turn(player2, plateau);

    if (sby_won(plateau)){
      std::cout<<"Le joueur "<<player2.name<<" a gagné!"<<std::endl;

      break;
    }
  }   
    
return 0;
}
