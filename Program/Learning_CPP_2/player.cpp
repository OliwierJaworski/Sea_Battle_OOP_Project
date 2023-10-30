#include "player.h"
#include "game_map.h"
#include <iostream>

Player::Player()
{
    map = new Game_Map;
    map->init_matrix();
}

void Player::print_name()
{
    std::cout << Name << std::endl;
}

void place_boatd()
{

}
