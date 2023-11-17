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
    void Game_Player::Attack_Enemy(Game_Player& current_player, Game_Player& enemy_player )
    {
        int x;
        int y;
        user_input();
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
    std::string user_input()
    {
    std::string User_Typed;

        do {
            std::cout << "Enter a location where you would like to hit: ";
            std::cin >> User_Typed;

            if (User_Typed.length() > 1)
            {
                std::cout << "Input too long. Please enter only one character." << std::endl;
            }

        } while (User_Typed.length() > 1);

        return User_Typed;

    }
//private
    void Game_Player::Free_Alloc()
    {
        delete map;
    }