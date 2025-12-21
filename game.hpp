#include<iostream>
#include "Player.hpp"

void turn(Player& player, char plateau[][3]);
void ia_turn(Player& ia, Player& player, char plateau[][3]);

bool sby_won(char plateau[][3]);

int block(char symbol_player, char plateau[][3]);