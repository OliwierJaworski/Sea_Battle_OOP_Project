#ifndef REMADE_SEA_BATTLE_GAME_MAP_H
#define REMADE_SEA_BATTLE_GAME_MAP_H

#include <vector>
#include <string>
#include <iostream>
#include <memory>



#include "../External_Data_Declaration/Data_Declaration.h"
#include "../Boats_Related/Boats_Destroyer.h"
#include "../Boats_Related/Boats_Carrier.h"

class Game_Map
{

public:
//constructor | destructor
    Game_Map();
    ~Game_Map() {Free_Alloc();};
//public

    void set_enemy_map();
    void set_my_map();
    const int get_my_map()          {}
    const int get_enemy_map()       {}
private:
//private
    std::vector<Game_Boats *> BoatsVector;
    TILE_INFO My_map[10][10];
    TILE_INFO Enemy_map[10][10];
    void Init_Boats();
    //void set_map_toempty(int map_to_empty[10][10]);
    bool Boats_Fill_Map();
    bool Will_Boat_Fit(Game_Boats& Boat_ID, int x, int y, int rot);
    void place_boats(Game_Boats& Boat_ID, int x, int y, int rot);
    void fill_boat_info(Game_Boats& Boat_ID);
    void Free_Alloc();
};
#endif
