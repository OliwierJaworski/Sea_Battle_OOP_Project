#ifndef PLAYER_H
#define PLAYER_H

#include "game_map.h"

#include <string>


class Player
{
    friend class Game_handler;

public:
    Player();
    void print_name();
    void place_boats();
    void auto_boat_placer(int baotsize);
    std::string player_input();

private:
    std::string Name;
    Game_Map * map;
};

#endif // PLAYER_H
