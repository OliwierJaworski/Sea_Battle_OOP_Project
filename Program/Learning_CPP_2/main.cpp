#include <QCoreApplication>
#include <iostream>
#include <string>

#include "player.h"
#include "game_handler.h"


int main()
{
    Game_handler game;

    Player* player1 = new Player;
    Player* player2 = new Player;

    game.Collect_Players_ID(player1);
    game.Collect_Players_ID(player2);

    printf("Code Still works!\n");

    game.clear_player_ID_list();

    return 0;
}
