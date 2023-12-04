#include "Online_Player.h"

Coordinates Online_Player::Attack_Enemy(Coordinates User_Input_Cords)
{
    Coordinates Attack_Cords =User_Input_Cords;
    return  Attack_Cords;
}
void Online_Player::Att_tile_state(Coordinates User_Input_Cords, bool Tile_State)//Tile_state is de return van u opponent
{
    map.Set_Enemy_map(User_Input_Cords.x,User_Input_Cords.y,Tile_State);
}
