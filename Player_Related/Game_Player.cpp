#include "Game_Player.h"
    Game_Player::~Game_Player()
    {

    }
    void Game_Player::Attack_Enemy(Game_Player & Enemy_Player,Coordinates User_Input_Cords)
    {
        Coordinates Attack_Enemy_Cords = User_Input_Cords;
        int x= Attack_Enemy_Cords.x;
        int y= Attack_Enemy_Cords.y;
        Enemy_Player.map.get_my_map(y,x);
    }

    bool  Game_Player::Get_Player_lost()
    {
        return true;
    }
    void Game_Player::print_map()
    {

    }


