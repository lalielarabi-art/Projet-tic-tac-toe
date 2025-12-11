#include <iostream>
#include "game.hpp"
#include "board.hpp"
#include "Player.hpp"


void turn(Player& player, char plateau[][3]){

      std::cout<<"Le joueur "<<player.name<<" doit jouer."<<std::endl;

      int box;
      std::cin >> box;

      int lign {(box-1)/3};
      int column {(box-1)%3};

      while (!(plateau[lign][column]>='1' and plateau[lign][column]<='9'))
    {
        std::cout<<"Cette case est déjà prise. Veuillez en choisir une autre."<<std::endl;
        std::cin>>box;
        lign = {(box-1)/3};
        column = {(box-1)%3};
    }

      plateau[lign][column]=player.symbol;

      draw_game_board(plateau);
    }

void ia_turn(Player& ia, char plateau[][3]){

    std::cout<<"Le joueur "<<ia.name<<" doit jouer."<<std::endl;

    std::vector<int> empty_boxes;
    for (int i{0}; i<3;++i){
        for(int j{0}; j<3; ++j){
            if (plateau[i][j]>= '1' and plateau[i][j]<= '9' ){
                empty_boxes.push_back(3*i + 1 + j);
            }
        }
    }

    bool sby_won(char plateau[][3]){

     /*/Verif des colonnes*/
    for (int i{0}; i<3; ++i){
        if(plateau[i][0]==plateau[i][1] and plateau[i][1]==plateau[i][2]){
        return true;
        }
    }
    /*/Verif des lignes*/
    for (int j{0}; j<3; ++j){
        if(plateau[0][j]==plateau[1][j] and plateau[1][j]==plateau[2][j]){
        return true;
        }
    }
    /*/Verif des diagos*/
    if (plateau[0][0]==plateau[1][1] and plateau[1][1]==plateau[2][2]){
        return true;
    }
    if (plateau[0][2]==plateau[1][1] and plateau[1][1]==plateau[2][0]){
        return true;
    }
    else{
        return false;
    }
}
