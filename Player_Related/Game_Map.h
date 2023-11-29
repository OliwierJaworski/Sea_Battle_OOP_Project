#ifndef REMADE_SEA_BATTLE_GAME_MAP_H
#define REMADE_SEA_BATTLE_GAME_MAP_H

#include <vector>
#include <string>
#include <iostream>
#include <memory>

#include "../Boats_Related/Boats_Destroyer.h"
#include "../Boats_Related/Boats_Carrier.h"
#include "../Boats_Related/Game_Boats.h"

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
    Game_Boats* get_boat(int size);

private:
//private
    std::vector<std::unique_ptr<Game_Boats>> BoatsVector;
    TILE_INFO My_map[10][10];
    TILE_INFO Enemy_map[10][10];
    void Init_Boats();
    //void set_map_toempty(int map_to_empty[10][10]);
    bool Boats_Fill_Map(Game_Boats& Boat_ID);
    bool Will_Boat_Fit(Game_Boats& Boat_ID, int x, int y, int rot);
    void place_boats(Game_Boats& Boat_ID, int x, int y, int rot);
    void Free_Alloc();
};


#endif
