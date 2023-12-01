#include "Game_Player.h"
    Game_Player::~Game_Player()
    {

    }
    void Game_Player::Attack_Enemy(Game_Player & Enemy_Player,Coordinates User_Input_Cords(std::string cordvalue))
    {
        Enemy_Player.map.get_my_map(User_Input_Cords());
    }

    bool  Game_Player::Get_Player_lost()
    {
        return true;
    }
    void Game_Player::print_map()
    {

    }


