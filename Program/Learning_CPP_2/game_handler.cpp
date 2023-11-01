#include "game_handler.h"

#include <string>
#include <iostream>
#include <time.h>

void Game_handler::start_Game(Game_handler * game)
{
    srand(time(NULL));

    Player* player1 = new Player;
    Player* player2 = new Player;

    game->Collect_Players_ID(player1);
    game->Collect_Players_ID(player2);

    int i=0;
    while (i<2)
    {
        i++;
        for (int ID = 0; ID < 2; ++ID)
        {
            if(ID==0)
            {
                std:: cout <<"player 1 map " << std::endl;
                player1->map->display_map();
                std:: cout <<"player 2 map " << std::endl;
                player2->map->display_map();

                player1->ask_if_hit(player_input(),game->playersVector[1]);
            }
            else
            {
                std:: cout <<"player 2 map " << std::endl;
                player2->map->display_map();
                std:: cout <<"player 1 map " << std::endl;
                player1->map->display_map();

                player2->map->display_map();
                player2->ask_if_hit(player_input(),game->playersVector[0]);
            }
        }
    }

    std::cout << "code still works" << std::endl;
    delete player1;
    delete player2;
    game->clear_player_ID_list();

}

void Game_handler::Collect_Players_ID(Player * playerX)
{
    playersVector.push_back(playerX);
}

void Game_handler::clear_player_ID_list()
{
    playersVector.clear();
    playersVector.shrink_to_fit();
}

std::string Game_handler::player_input()
{
    std::string char_input_1;
    std::string char_input_2;
    std::cout << "first coordinate :" <<std::endl;
    std::cin >> char_input_1;
    std::cout << "Second coordinate :" <<std::endl;
    std::cin >> char_input_2;

    std::string coordinate_pair = char_input_1 + "," + char_input_2;
    return coordinate_pair;
}
