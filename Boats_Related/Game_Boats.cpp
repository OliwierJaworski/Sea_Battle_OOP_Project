#include "Game_Boats.h"
void Game_Boats::Init_Boat_Tiles()
{
    for (int i = 0; i < Get_Size(); ++i)
    {
        std::unique_ptr<TILE_INFO> curr_ship_part =std::make_unique<TILE_INFO>();
        ship_info.push_back(std::move(* curr_ship_part));
    }
}
void Game_Boats::set_Boat_tile(int x, int y,int IsHit, int ship_part )
{
    ship_info[ship_part].tile_status =SHIP;
    ship_info[ship_part].x = x;
    ship_info[ship_part].y = y;

    std::cout << " ship_info[ship_part].tile_status :"<<  ship_info[ship_part].tile_status
              << " ship_info[ship_part].x"            <<  ship_info[ship_part].x
              << " ship_info[ship_part].y"            <<  ship_info[ship_part].y <<std::endl;
}