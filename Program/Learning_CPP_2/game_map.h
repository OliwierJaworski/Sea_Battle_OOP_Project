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
    int Calc_Boat_Fit(int x, int y, int size, int boat_rot);
    void clear_boats_data();//dit moet private anders kan iedereen boatsdataclearen
private:
    int game_matrix[10][10];
    std::vector<boats *> BoatVector;
};

#endif // GAME_MAP_H
