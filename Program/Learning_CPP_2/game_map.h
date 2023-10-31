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
    int Calc_Boat_Fit(int y, int x, int size, int boat_rot);
    void Boat_Map_Placer(int y, int x, int size, int boat_rot);
    void display_map();
    void clear_boats_data();//dit moet private anders kan iedereen boatsdataclearen
private:
    int game_matrix[10][10];
    std::vector<boats *> BoatVector;
};

#endif // GAME_MAP_H
