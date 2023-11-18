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
        bool targeted_area;

        x=user_input();
        y=user_input();
        targeted_area= enemy_player.Did_enemy_hit(y,x);


        if(targeted_area)
        {
            current_player.map->set_enemy_map(x,y,true);

        }
        else
        {
            current_player.map->set_enemy_map(x,y,false);
        }
    }
    bool Game_Player::Did_enemy_hit(int y, int x)
    {
        int contained_ship;

        if(map->get_my_map(x,y)>0 && map->get_my_map(x,y) <6)//hitttttt
        {
            contained_ship = map->get_my_map(x,y);
            map->get_boat(contained_ship)->Take_Damage(1);

            std::cout << map->get_boat(contained_ship)->get_Health_Amount() << std::endl;

            map->set_my_map(x,y,true);
            return true;
        }
        else //missssss
        {
            map->set_my_map(x,y,false);
            return false;
        }
    }
    void Game_Player::print_map(Game_Map & Used_map, int whichmap)
    {
    //std::cout << "\U0001F7E6"<< std::endl;
        switch (whichmap)
        {
            case 0:
                std::cout << "my map"<<std::endl;
                for (int i = 0; i < 10; ++i)
                {
                    for (int j = 0; j < 10; ++j)
                    {
                        if (Used_map.get_my_map(i,j)==0)
                        {
                            std::cout << "\U0001F7E6";
                        }
                        if(Used_map.get_my_map(i,j)>0 && Used_map.get_my_map(i,j)< 6)
                        {
                            std::cout << "\U0001F532";
                        }
                        if (Used_map.get_my_map(i,j)==8)
                        {
                            std::cout << "\\U0001F4A6";
                        }
                        if (Used_map.get_my_map(i,j)==9)
                        {
                            std::cout << "\U0001F525";
                        }

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
                        if (Used_map.get_enemy_map(i,j)==0)
                        {
                            std::cout << "\U0001F7E6";
                        }
                        if(Used_map.get_enemy_map(i,j)>0 && Used_map.get_enemy_map(i,j)< 6)
                        {
                            std::cout << "\U0001F532";
                        }
                        if (Used_map.get_enemy_map(i,j)==8)
                        {
                            std::cout << "\U0001F525";
                        }
                        if (Used_map.get_enemy_map(i,j)==9)
                        {
                            std::cout << "\U0001F4A6";
                        }

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