#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "game_map.h"

class Player
{
    friend class Game_handler;

public:
    Player();
    void print_name();
    void place_boats();
private:
    std::string Name;
    Game_Map * map;
};

#endif // PLAYER_H
