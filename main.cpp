#include <iostream>
#include "time.h"
#include "Game_Manager_Related/Game_Manager_Loader.h"

int main()
{
    srand(time(NULL));

    Game_Manager_Loader game;
    game.Game_Type(game.Player_Option());
    return 0;
}
