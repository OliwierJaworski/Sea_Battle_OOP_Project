#ifndef REMADE_SEA_BATTLE_GAME_MAP_H
#define REMADE_SEA_BATTLE_GAME_MAP_H

#include <vector>
#include <string>
#include <iostream>


#include "Boats_Destroyer.h"
#include "Boats_Carrier.h"

class Game_Map
{

public:
//constructor | destructor
    Game_Map() ;
    ~Game_Map() {Free_Alloc();};
//public
    void set_enemy_map(int x, int y);
    const int get_my_map(int x, int y)                                                      const {return My_map[x][y];}
    const int get_enemy_map(int x, int y)                                                   const {return Enemy_map[x][y];}
    const int Player_Life_Left();
private:
//private
    std::vector<Game_Boats *> BoatsVector;
    int My_map[64][64];
    int Enemy_map[64][64];
    void Init_Boats();
    void set_map_toempty(int map_to_empty[64][64]);
    bool Boats_Fill_Map(Game_Boats& Boat_ID);
    bool Will_Boat_Fit(Game_Boats& Boat_ID, int x, int y, int rot);
    void place_boats(Game_Boats& Boat_ID, int x, int y, int rot);
    void Free_Alloc();

};


#endif
