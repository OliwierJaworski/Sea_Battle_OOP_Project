#include "Game_Player.h"

//constructor | destructor
    Game_Player::Game_Player()
    {
        Init_Map();
        print_player_map(* map);
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
   void Game_Player::print_player_map(Game_Map & my_map)
    {
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
               std::cout <<  my_map.get_my_map(i,j);
            }
            std::cout << std::endl;
        }
    }
//private
    void Game_Player::Free_Alloc()
    {
        delete map;
    }