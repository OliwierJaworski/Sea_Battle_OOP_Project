#include <iostream>

#include "Game_Manager.h"


//constructor | destructor
    Game_Manager::Game_Manager()
    {
        Init_Players();
    }
    Game_Manager::~Game_Manager()
    {
        Free_Alloc();
    }
//public
    Game_Player* Game_Manager::Get_Player_ID(int requested_id)
    {
        if(requested_id >= 0 && requested_id < PlayerVector.size())
        {
            return PlayerVector.at(requested_id);
        }
        else
        {
            std::cout << "not valid ID" << std::endl;
            return nullptr;
        }
    }
    int Game_Manager::Play_Game()
    {

    }
//private
    void Game_Manager::Init_Players()
    {
        Game_Player * player1 =new Game_Player;
        Game_Player * player2 =new Game_Player;

        PlayerVector.push_back(player1);
        PlayerVector.push_back(player2);
    }
    void Game_Manager::Free_Alloc()
    {
        for (int i = 0; i < 1; ++i)
        {
            PlayerVector.erase(PlayerVector.begin()+ i);
        }
        PlayerVector.shrink_to_fit();
    }