    #include <iostream>
    #include <memory>
    #include "Game_Manager.h"

    Game_Manager::Game_Manager()
    {
        Init_Players();
    }
    Game_Manager::~Game_Manager()
    {

    }
    //public
    bool Game_Manager::Is_Game_Finished()
    {

    }

    int Game_Manager::Play_Game()
    {
        int playersturn = 0;
        while (!Is_Game_Finished())
        {
            PlayTurns(& playersturn);
        }
        return 0;
    }
    void Game_Manager::PlayTurns(int * playersturn)
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
    void Game_Manager::Init_Players()
    {
        std::unique_ptr<Game_Player> player2 =std::make_unique<Game_Player>();
        std::unique_ptr<Game_Player> player1 =std::make_unique<Game_Player>();

        PlayerVector.push_back(std::move(player1));
        PlayerVector.push_back(std::move(player2));
    }





