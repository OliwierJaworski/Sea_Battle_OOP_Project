#ifndef GAME_MAP_H
#define GAME_MAP_H

#include "boats.h"
#include <vector>

class Game_Map
{
    friend class Player;
public:
    void init_matrix();
    void init_boats();
    void clear_boats_data();
private:
    int game_matrix[4][4];
    std::vector<boats *> BoatVector;
};

#endif // GAME_MAP_H
