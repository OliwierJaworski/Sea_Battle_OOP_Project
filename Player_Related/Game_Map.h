#ifndef REMADE_SEA_BATTLE_GAME_MAP_H
#define REMADE_SEA_BATTLE_GAME_MAP_H

#include <vector>
#include <string>
#include <iostream>
#include <memory>

#include "../Boats_Related/Boats_Destroyer.h"
#include "../Boats_Related/Boats_Carrier.h"
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
struct TILE_INFO
{
    int x;//cords of part of ship
    int y;
    int tile_status = WATER;
    std::shared_ptr<Game_Boats *> ship_on_tile = nullptr;//easier way to iterate through ships
};

class Game_Map
{

public:
//constructor | destructor
    Game_Map();
    ~Game_Map() {Free_Alloc();};

public:
//public
    void set_enemy_map();
    void set_my_map();
    const int get_my_map()          {}
    const int get_enemy_map()       {}
private:
//private
    std::vector<Game_Boats *> BoatsVector;
    TILE_INFO my_map;
    TILE_INFO My_map[10][10];
    TILE_INFO Enemy_map[10][10];
    void Init_Boats();
    bool Boats_Fill_Map();
    bool Will_Boat_Fit(Game_Boats& Boat_ID, int x, int y, int rot);
    void place_boats(Game_Boats& Boat_ID, int x, int y, int rot);
    void Free_Alloc();
};
#endif
