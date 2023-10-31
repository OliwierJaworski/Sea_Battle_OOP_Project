#include "player.h"
#include "game_map.h"

#include <iostream>
#include <time.h>

Player::Player()
{
    map = new Game_Map;
    map->init_matrix();
    map->init_boats();
    for (int var = 0; var < (int)map->BoatVector.size(); ++var)
    {
        auto_boat_placer(map->BoatVector[var]->boatsize);
    }
}

void Player::print_name()
{
    std::cout << Name << std::endl;
}

std::string Player::player_input()
{
    std::string char_input;
    std::cin >> char_input;

    return char_input;
}

void Player::auto_boat_placer(int boatsize)
{
    srand(time(NULL));
    int random_index_x=rand()%10;
    int random_index_y=rand()%10;
    int boat_rot=rand()%4;
    int willfit = 0;
    while(willfit ==0)
    {
        willfit= map->Calc_Boat_Fit(random_index_x,random_index_y,boatsize, boat_rot);
    }
}


