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
    void clear_boats_data();//dit moet private anders kan iedereen boatsdataclearen

    std::string player_input_tile(int current_boat);
    std::string player_input_direction(int current_boat);

    int verify_boat_placement(std::string loc, std::string rot, int currentboat_size);
    void place_boats(std::string loc, std::string rot,int Can_place, int currentboat_size);
private:
    int game_matrix[10][10];
    std::vector<boats *> BoatVector;
};

#endif // GAME_MAP_H
