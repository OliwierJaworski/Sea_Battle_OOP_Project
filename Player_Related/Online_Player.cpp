#include "Online_Player.h"
Coordinates Online_Player::Attack_Enemy(std::string input_string)
{
        Coordinates User_Cords;
        std::string::size_type pos = input_string.find('.');
        User_Cords.y = input_string.at(pos + 1) - '0';
        User_Cords.x = input_string.at(pos - 1) - '0';

            return User_Cords;
}
void Online_Player::adj_map_ToResponse(int y,int x, bool tile_state)
{
    get_map().Set_Enemy_map(x,y,tile_state);
}
bool Online_Player::adj_MyMAP_TOResponse(int x, int y)
{
    return get_map().get_my_map(x,y);
}


