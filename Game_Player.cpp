#include "Game_Player.h"

//constructor | destructor
    Game_Player::Game_Player()
    {
        Init_Map();
    }
    Game_Player::~Game_Player()
    {
        Free_Alloc();
    }
//public
    bool Game_Player::Get_Player_lost()
    {
        if(map->Player_Life_Left()==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void Game_Player::Attack_Enemy(int x, int y, Game_Player& current_player, Game_Player& enemy_player )
    {

    }
//private
    void Game_Player::Free_Alloc()
    {
        delete map;
    }