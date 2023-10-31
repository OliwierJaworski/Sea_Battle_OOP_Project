#include "game_handler.h"

#include <string>
#include <iostream>

void Game_handler::start_Game(Game_handler * game)
{
    Player* player1 = new Player;
    Player* player2 = new Player;

    game->Collect_Players_ID(player1);
    game->Collect_Players_ID(player2);


    printf("Code Still works!\n");

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

