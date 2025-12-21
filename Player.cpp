#include <iostream>
#include "Player.hpp"

Player create_player(){
    Player player;

    std::cout <<"Entrez le nom du joueur:"<<std::endl;
    std::cin>> player.name;

    std::cout <<"Choissisez un symbole:"<<std::endl;
    std::cin>> player.symbol;

    std::cout << " Le joueur " << player.name << " joue avec le symbole '" << player.symbol << "'" << std::endl;

    return player;
}


