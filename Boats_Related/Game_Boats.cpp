#include "Game_Boats.h"
void Game_Boats::set_ship_tile(int x, int y,int IsHit, int ship_part )
{
    ship_info[ship_part].tile_status =SHIP;
    ship_info[ship_part].x = x;
    ship_info[ship_part].y = y;
}