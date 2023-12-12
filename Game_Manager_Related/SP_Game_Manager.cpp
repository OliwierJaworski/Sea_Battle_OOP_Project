#include "SP_Game_Manager.h"
bool SP_Game_Manager::Play_Game()
{
    while(Game_State_active())
    {

    }
    return true;
}



bool SP_Game_Manager::Game_State_active()
{
    if (Player_Me.Get_Player_boats_alive() && Player_Enemy.Get_Player_boats_alive())
    {
        return true;
    }
    return false;
}

Coordinates SP_Game_Manager::tranlate_to_cords(std::string input_string)
{
    Coordinates User_Cords;
    std::string::size_type pos =input_string.find('.');
    User_Cords.y = input_string.at(pos +1)-'0';
    User_Cords.x = input_string.at(pos -1)-'0';
    return  User_Cords;
}

