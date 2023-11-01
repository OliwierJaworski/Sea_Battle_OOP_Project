#include "player.h"
#include "game_map.h"

#include <iostream>


Player::Player()
{
    map = new Game_Map;
    map->init_matrix();
    map->init_boats();
    map->display_map();
    std::cout << "before" << std::endl;

    for (int var = 0; var < (int)map->BoatVector.size(); ++var)
    {
        std::cout << "boat: " << map->BoatVector[var]->boatname<<std::endl;
        std::cout << "size of boat: " << map->BoatVector[var]->boatsize<<std::endl;
        auto_boat_placer(map->BoatVector[var]->boatsize);

    }

    std::cout << "new" <<std::endl;
    map->display_map();
    std::cout << std::endl;
}

void Player::print_name()
{
    std::cout << Name << std::endl;
}



void Player::auto_boat_placer(int boatsize)
{
    int random_index_x;
    int random_index_y;
    int boat_rot;
    int willfit = 1;

    while(willfit !=0)
    {
        random_index_x= rand()%10;
        random_index_y= rand()%10;
        boat_rot= rand()%4;

        std::cout<< "y:" <<random_index_y << " x:" << random_index_x << std::endl;
        willfit= map->Calc_Boat_Fit(random_index_x,random_index_y,boatsize, boat_rot);//checks whether the chosen boat size,cords are not out of bound or dont hit other ships
    }
    std::cout << " found a spot for the boat" << std::endl;
    map->Boat_Map_Placer(random_index_x,random_index_y,boatsize, boat_rot);
}

int Player::ask_if_hit(const std::string& coordinate, Player* opponent)
{
    size_t sign_pos = coordinate.find(',');
        int firstPart_cord=-1;
        int SecondPart_cord=-1;

    if (sign_pos != std::string::npos)
    {
        firstPart_cord = std::stoi(coordinate.substr(0, sign_pos));
        SecondPart_cord = std::stoi(coordinate.substr(sign_pos + 1));

    }
    if( opponent->map->game_matrix[SecondPart_cord][firstPart_cord]>=1)
    {
        std::cout << " hit :)" << std::endl;
        map->enemy_game_matrix[SecondPart_cord][firstPart_cord]=1;
        return 1;//hit!
    }
    else
    {
        std::cout << " miss :(" << std::endl;
        return 0;//miss!
    }

}

