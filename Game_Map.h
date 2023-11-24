#ifndef REMADE_SEA_BATTLE_GAME_MAP_H
#define REMADE_SEA_BATTLE_GAME_MAP_H

#include "Boats_Destroyer.h"
#include "Boats_Carrier.h"
#include <vector>
class Game_Map
{

public:
//constructor | destructor
    Game_Map() ;
    ~Game_Map() {Free_Alloc();};
//public
//Map Core structure
    const int Get_Player_Life_Left();
    void set_enemy_map(int x, int y,bool hit_or_mis);
    void set_my_map(int x, int y,bool hit_or_mis);
    void Online_Set_my_map(std::vector<std::vector<int>> cordvector);
    const int get_my_map(int x, int y)const                 {return My_map[x][y];}
    const int get_enemy_map(int x, int y)const              {return Enemy_map[x][y];}

//extra added functionality
    Game_Boats* get_boat(int size);

private:
//private
//Map Core structure
    std::vector<Game_Boats *> BoatsVector;
    int My_map[10][10];
    int Enemy_map[10][10];

//initialization & destruction
    void Init_Boats();
    void Free_Alloc();
    bool Boats_Fill_Map(Game_Boats& Boat_ID);
    bool Will_Boat_Fit(Game_Boats& Boat_ID, int x, int y, int rot);
    void place_boats(Game_Boats& Boat_ID, int x, int y, int rot);
};
#endif
