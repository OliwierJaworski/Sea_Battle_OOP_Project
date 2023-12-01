#include "Game_Boats.h"
void Game_Boats::shipvector_element_amount()
{
    for (int i = 0; i < Boat_size; ++i)
    {
        std::unique_ptr<TILE_INFO> tile =std::make_unique<TILE_INFO>();
        ship_info.push_back(std::move(tile));
    }
}
void Game_Boats::set_ship_tile(int x, int y,int IsHit, int ship_part )
{
    ship_info[ship_part]->tile_status =SHIP;
    ship_info[ship_part]->x = x;
    ship_info[ship_part]->y = y;
    std::cout << "the following ship part :" << ship_part << "on x :" << ship_info[ship_part]->x << " and y :" << ship_info[ship_part]->y << "is now a ship "<< ship_info[ship_part]->tile_status <<std::endl;
}