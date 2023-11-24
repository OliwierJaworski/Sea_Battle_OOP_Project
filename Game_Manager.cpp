#include <iostream>
#include <memory>

#include "Game_Manager.h"
Game_Manager::Game_Manager()
{

}
Game_Manager::~Game_Manager()
{

}

//constructor | destructor
    SP_Game_Manager::SP_Game_Manager()
    {
        Init_Players();
    }
    SP_Game_Manager::~SP_Game_Manager()
    {

    }
//public
    bool SP_Game_Manager::Is_Game_Finished()
    {
        //check for win condition
        for (int playeriterator = 0; playeriterator < PlayerVector.size(); ++playeriterator)
        {
            if (PlayerVector.at(playeriterator)->Get_Player_lost())
            {
                std::cout << "player called (moet nog implementeren) has lost " << std::endl;
               return true;
            }
        }
        return false;
    }

    int SP_Game_Manager::Play_Game()
    {
        int playersturn = 0;
        while (!Is_Game_Finished())
        {
            PlayTurns(& playersturn);
        }
        return 0;
    }
    void SP_Game_Manager::PlayTurns(int * playersturn)
    {
        if (* playersturn==0)
        {
            std::cout << "PLAYER 1" << std::endl;
            PlayerVector[* playersturn]->print_map( PlayerVector[* playersturn]->map,0);
            PlayerVector[* playersturn]->print_map( PlayerVector[* playersturn]->map,1);

            PlayerVector[* playersturn]->Attack_Enemy(* PlayerVector[* playersturn],* PlayerVector[* playersturn +1]);
            *playersturn=1;
        }
        else
        {
            std::cout << "PLAYER 2" << std::endl;
            PlayerVector[* playersturn]->print_map( PlayerVector[* playersturn].get()->map,0);
            PlayerVector[* playersturn]->print_map( PlayerVector[* playersturn].get()->map,1);

            PlayerVector[* playersturn]->Attack_Enemy(* PlayerVector[* playersturn],* PlayerVector[* playersturn -1]);
            *playersturn=0;
        }
    }

//private
    void SP_Game_Manager::Init_Players()
    {
        std::unique_ptr<Game_Player> player2 =std::make_unique<Game_Player>();
        std::unique_ptr<Game_Player> player1 =std::make_unique<Game_Player>();

        PlayerVector.push_back(std::move(player1));
        PlayerVector.push_back(std::move(player2));
    }
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////