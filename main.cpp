#include <iostream>
#include <time.h>

#include "Game_Manager.h"

int main()
{
    srand(time(NULL));
    std::string gametype;
    std::cout << "which Game mode you want to start" << std::endl;
    do
    {
        std::cin >> gametype;
    }
   while(gametype!="singleplayer"&&gametype!="Host"&&gametype!="Client");

        if (gametype == "singleplayer")
        {
            SP_Game_Manager game;
            game.Play_Game();
        } else if (gametype == "Host")
        {
            Host_Game_Manager game;
            game.Play_Game();
        } else if (gametype == "Client")
        {
            Client_Game_Manager game;
            game.Play_Game();
        }
    return 0;
}

