#include "Game_Manager.h"


int main()
{
    srand(time(NULL));

    Game_Manager  game;
    game.Game_Loop();

    return 0;
}

