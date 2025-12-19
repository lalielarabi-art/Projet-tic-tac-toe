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


void ia_turn(Player& ia, Player& player, char plateau[][3]){

    std::cout<<"Le joueur "<<ia.name<<" a joué."<<std::endl;
    int box;
    bool played=false;

    box=block(ia.symbol, plateau);
    if(box!=-1){
        int lign {(box-1)/3};
        int column {(box-1)%3};

        plateau[lign][column]=ia.symbol;

        draw_game_board(plateau);
        played=true;
    }

    box=block(player.symbol, plateau);
    if(box!=-1){
        int lign {(box-1)/3};
        int column {(box-1)%3};

        plateau[lign][column]=ia.symbol;

        draw_game_board(plateau);
        played=true;
    }

    else if (played==false){
    std::vector<int> empty_boxes;
    for (int i{0}; i<3;++i){
        for(int j{0}; j<3; ++j){
            if (plateau[i][j]>= '1' and plateau[i][j]<= '9' ){
                empty_boxes.push_back(3*i + 1 + j);
            }

        }
    }
   
    int index_box= rand()% empty_boxes.size();
    int box = empty_boxes[index_box];

    int lign {(box-1)/3};
    int column {(box-1)%3};

    plateau[lign][column]=ia.symbol;

    draw_game_board(plateau);
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

int block(char symbol_player, char plateau[][3]){

    int count_player;
    int count_empty;
    int empty_box_index;

    for (int i = 0; i < 3; i++){

        int count_player = 0;
        int count_empty = 0;
        int empty_box_index {};

        for(int j = 0; j < 3; ++j) { 
            if(plateau[i][j] == symbol_player) {
                count_player++;
            }
            else if(plateau[i][j] >= '1' and plateau[i][j] <= '9') {
                    empty_box_index=3*i + 1 + j;
                    count_empty++;
            }

            if (count_player == 2 and count_empty == 1){
                return empty_box_index;
            }
        
        }
        if (count_player == 2 and count_empty == 1)
            return empty_box_index;
    }

    for (int j = 0; j < 3; j++) {
        count_player = 0;
        count_empty = 0;
        empty_box_index = -1;

        for (int i = 0; i < 3; i++) {
            if (plateau[i][j] == symbol_player)
                count_player++;
            else if (plateau[i][j] >= '1' and plateau[i][j] <= '9') {
                count_empty++;
                empty_box_index = 3 * i + j + 1;
            }
        }

        if (count_player == 2 and count_empty == 1)
            return empty_box_index;
    }

    count_player = 0;
    count_empty = 0;
    empty_box_index = -1;

    for (int i = 0; i < 3; i++) {
        if (plateau[i][i] == symbol_player)
            count_player++;
        else if (plateau[i][i] >= '1' and plateau[i][i] <= '9') {
            count_empty++;
            empty_box_index = 3 * i + i + 1;
        }
    }

    if (count_player == 2 and count_empty == 1)
        return empty_box_index;

    count_player = 0;
    count_empty = 0;
    empty_box_index = -1;

    for (int i = 0; i < 3; i++) {
        int j = 2 - i;

        if (plateau[i][j] == symbol_player)
            count_player++;
        else if (plateau[i][j] >= '1' and plateau[i][j] <= '9') {
            count_empty++;
            empty_box_index = 3 * i + j + 1;
        }
    }

    if (count_player == 2 && count_empty == 1)
        return empty_box_index;


    return -1;
}
