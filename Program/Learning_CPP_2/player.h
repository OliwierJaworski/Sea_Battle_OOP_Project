#ifndef PLAYER_H
#define PLAYER_H

#include "game_map.h"

#include <string>


class Player
{
    friend class Game_handler;

public:
    Player();
    ~Player() {delete map;};
    void print_name();
    void place_boats();
    void auto_boat_placer(int baotsize);
    int ask_if_hit(const std::string& coordinate, Player* opponent);

private:
    std::string Name;
    Game_Map * map;
};

#endif // PLAYER_H
