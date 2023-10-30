#include "player.h"
#include "game_map.h"
#include "boats.h"

#include <iostream>

Player::Player()
{
    map = new Game_Map;
    map->init_matrix();
    map->init_boats();

    for (int var = 0; var < map->BoatVector.size(); ++var)
    {
        boats * Ptr_Adr = map->BoatVector[var];
        std::cout << map->BoatVector[var] << std::endl;
        std::cout << Ptr_Adr->boatsize << std::endl;
        std::cout << Ptr_Adr->boatname << std::endl;
    }
}

void Player::print_name()
{
    std::cout << Name << std::endl;
}

void Player::place_boats()
{
    for (int var = 0; var < 5; ++var)
    {
        int x_loc;
        int y_loc;
        int x_loc_next;
        int y_loc_next;
        std::cout << "where would you like to place the " << map->BoatVector[var]->boatname << " of size " << map->BoatVector[var]->boatsize << std::endl;
        std::cout << "in which direction (just use the tile loc)" <<std::endl;
        if(map->game_matrix[x_loc][y_loc] ==0)
        {
            if()
        }
    }
}
