#include "game_handler.h"

#include <string>
#include <iostream>

void Game_handler::start_Game()
{

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
