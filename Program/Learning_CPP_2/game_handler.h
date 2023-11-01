#ifndef GAME_HANDLER_H
#define GAME_HANDLER_H

#include "player.h"

#include <string>
#include <vector>

class Game_handler
{
public:
    void start_Game(Game_handler * game);
    void Collect_Players_ID(Player * playerX);
    void clear_player_ID_list();
    std::string player_input();
private:
    std::vector< Player *> playersVector;
};

#endif // GAME_HANDLER_H
