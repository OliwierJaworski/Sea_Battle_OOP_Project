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
    const Game_Player* Game_Manager::Get_Player_ID(int requested_id)
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
        bool Is_Game_Finished = false;
        int playersturn = 0;

        while (!Is_Game_Finished)
        {
            //check for win condition
            for (int playeriterator = 0; playeriterator < PlayerVector.size(); ++playeriterator)
            {
                if (PlayerVector.at(playeriterator)->Get_Player_lost())
                {
                    std::cout << "player called (moet nog implementeren) has lost" << std::endl;
                    Is_Game_Finished = true;
                }
            }
            //if no one has lost yet continue loop
            PlayTurns(& playersturn);
        }

        std::cout << "game ended" << std::endl;
        return 0;
    }
    void Game_Manager::PlayTurns(int * playersturn)
    {
        if (* playersturn==0)
        {
            PlayerVector[* playersturn]->print_map( * PlayerVector[* playersturn]->map,0);
            PlayerVector[* playersturn]->print_map( * PlayerVector[* playersturn]->map,1);

            PlayerVector[* playersturn]->Attack_Enemy(* PlayerVector[* playersturn],* PlayerVector[* playersturn +1]);
            *playersturn=1;
        }
        else
        {
            PlayerVector[* playersturn]->print_map( * PlayerVector[* playersturn]->map,0);
            PlayerVector[* playersturn]->print_map( * PlayerVector[* playersturn]->map,1);

            PlayerVector[* playersturn]->Attack_Enemy(* PlayerVector[* playersturn],* PlayerVector[* playersturn -1]);
            *playersturn=0;
        }
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
        for (int i = 0; i < PlayerVector.size(); ++i)
        {
            PlayerVector.erase(PlayerVector.begin()+ i);
        }
        PlayerVector.shrink_to_fit();
    }