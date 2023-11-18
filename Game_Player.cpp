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
        int targeted_area;

        x=user_input();
        y=user_input();
        targeted_area= enemy_player.Get_friendly_map_loc_value(x,y);

        if (targeted_area>0 && targeted_area<6)
        {
            std::cout<< "kaboom!!!"<< std::endl;
            current_player.Set_enemy_map_hit_attempt(x,y,true);
        }
        else
        {
            std::cout<< "unfortunate miss!!!" << std::endl;
            current_player.Set_enemy_map_hit_attempt(x,y,false);
        }
    }
    void Game_Player::print_map(Game_Map & Used_map, int whichmap)
    {
        switch (whichmap)
        {
            case 0:
                std::cout << "my map"<<std::endl;
                for (int i = 0; i < 10; ++i)
                {
                    for (int j = 0; j < 10; ++j)
                    {
                        std::cout <<  Used_map.get_my_map(i,j);
                    }
                    std::cout << std::endl;
                }
                std::cout << std::endl;
                std::cout << std::endl;
                break;
            case 1:
                std::cout << "my enemy map"<<std::endl;
                for (int i = 0; i < 10; ++i)
                {
                    for (int j = 0; j < 10; ++j)
                    {
                        std::cout <<  Used_map.get_enemy_map(i,j);
                    }
                    std::cout << std::endl;
                }
                std::cout << std::endl;
                std::cout << std::endl;
                break;
        }


    }
    int Game_Player::user_input()
    {
        int User_Typed;

        do {
            std::cout << "Enter a  valid location where you would like to hit: ";
            std::cin >> User_Typed;



        } while (User_Typed>9 || User_Typed<0);

        return User_Typed;

    }
//private
    void Game_Player::Free_Alloc()
    {
        delete map;
    }