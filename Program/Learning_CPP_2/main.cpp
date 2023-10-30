#include <QCoreApplication>
#include <iostream>
#include <string>

#include "game_handler.h"


int main()
{
    Game_handler *game = new Game_handler;
    game->start_Game(game);

    delete game;
    return 0;
}
