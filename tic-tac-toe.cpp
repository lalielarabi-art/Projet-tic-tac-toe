#include <iostream>
#include "Player.hpp"
#include "board.hpp"


int main() {

std::cout<<"Bienvenue dans le jeu du TicTacToe" <<std::endl;
std::cout<< "Veuillez choisir un mode de jeu :"<<std::endl;
std::cout<<"1. Deux joueurs"<<std::endl;
std::cout<<"2. Un joueur contre l'IA"<<std::endl;

int game_mode{};
std::cin>> game_mode;

if (game_mode==1){
        
    Player player1 = create_player();
    Player player2 = create_player();
        
          
    
    char plateau[3][3]={
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };
        
    int box {};
        
    draw_game_board(plateau); 
    
    for(int i{0}; i<4; ++i){
    
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
   if (!sby_won(plateau)){
    turn(player1, plateau);
    if (sby_won(plateau)){
      std::cout<<"Le joueur "<<player1.name<<" a gagné!"<<std::endl;
    }
    
    if (!sby_won(plateau)){
        std::cout<<"La partie est terminé, le match est nul."<<std::endl;
      }
}

else{
    Player player = create_player();
    Player ia={"ia", '*'};

    char plateau[3][3]={
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
  };

  draw_game_board(plateau);

    for(int i{0}; i<4; ++i){

    turn(player, plateau);

    if (sby_won(plateau)){
      std::cout<<"Le joueur "<<player.name<<" a gagné!"<<std::endl;

      break;
    }

    ia_turn(ia, plateau);

    if (sby_won(plateau)){
      std::cout<<"Le joueur "<<ia.name<<" a gagné!"<<std::endl;

      break;
    }

  }
    
  if (!sby_won(plateau)){
    turn(player, plateau);
    if (sby_won(plateau)){
      std::cout<<"Le joueur "<<player.name<<" a gagné!"<<std::endl;
    }
  }

  if (!sby_won(plateau)){
    std::cout<<"La partie est terminé, le match est nul."<<std::endl;
  }
}

return 0;
}
