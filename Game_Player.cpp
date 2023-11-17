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

    }
    const int Game_Player::Get_friendly_map_loc_value()
    {

    }
    void Game_Player::Attack_Enemy(int x, int y, Game_Player& current_player, Game_Player& enemy_player )
    {

    }
//private
    void Game_Player::Free_Alloc()
    {
        delete map;
    }