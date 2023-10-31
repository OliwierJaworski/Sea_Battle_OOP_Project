#include "player.h"
#include "game_map.h"
#include "boats.h"

#include <iostream>

Player::Player()
{
    map = new Game_Map;
    map->init_matrix();
    map->init_boats();

    for (int var = 0; var < map->BoatVector.size() - 1; ++var)
    {
       //place boats on field ->functies in map zijn echt shit anders maken!!!
    }
}

void Player::print_name()
{
    std::cout << Name << std::endl;
}

