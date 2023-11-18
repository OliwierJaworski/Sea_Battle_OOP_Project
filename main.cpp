#include <iostream>
#include <time.h>

#include "Game_Manager.h"

int main()
{
    srand(time(NULL));

    Game_Manager  game;
    game.Play_Game();

    return 0;
}

