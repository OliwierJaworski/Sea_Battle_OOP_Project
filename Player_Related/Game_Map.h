#ifndef REMADE_SEA_BATTLE_GAME_MAP_H
#define REMADE_SEA_BATTLE_GAME_MAP_H

#include <vector>
#include <string>
#include <iostream>
#include <memory>

#include "../Boats_Related/Boats_Destroyer.h"
#include "../Boats_Related/Boats_Carrier.h"
#include "../Boats_Related/Game_Boats.h"
enum TILE_STATE
{
    MISS,
    HIT,
    SHIP,
    WATER
};
enum Rotation_Direction
{
    TO_RIGHT,
    TO_LEFT,
    UP,
    DOWN
};


class Game_Map
{

public:
//constructor | destructor
    Game_Map();
    ~Game_Map() {Free_Alloc();};

public:
//public
    //void set_enemy_map();
    //void set_my_map();
    //const int get_my_map()          {}
    //const int get_enemy_map()       {}
private:
//private
    std::vector<Game_Boats *> BoatsVector;
    int My_map[10][10];
    //int Enemy_map[10][10];

    void Init_Boats();
    bool Boats_Fill_Map();
    bool Will_Boat_Fit(Game_Boats& Boat_ID, int x, int y, int rot);
    void place_boats(Game_Boats& Boat_ID, int x, int y, int rot);
    void Free_Alloc();
};
#endif
