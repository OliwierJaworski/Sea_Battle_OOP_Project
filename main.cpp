#include <iostream>
#include <time.h>

#include "Game_Manager.h"

void start_game(Game_Manager  game);

int main()
{
    srand(time(NULL));
    Game_Manager  game;
    start_game(game);

    return 0;
}

void start_game(Game_Manager game)
{
   game.Play_Game();
}