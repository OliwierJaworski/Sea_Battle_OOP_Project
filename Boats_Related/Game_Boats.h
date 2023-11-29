#ifndef REMADE_SEA_BATTLE_GAME_BOATS_H
#define REMADE_SEA_BATTLE_GAME_BOATS_H

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "../Player_Related/Game_Map.h"

class Game_Boats
{
friend class Game_Map;
public:
    struct TILE_INFO
    {
        int x;//cords of part of ship
        int y;
        int tile_status = WATER;
        std::shared_ptr<Game_Boats> ship_on_tile = nullptr; //easier way to iterate through ships
    };

//constructor | destructor
    Game_Boats() : Boat_size(0){}
    virtual ~Game_Boats() {};

    int Get_Size()                         {return Boat_size;}

protected:
    int Boat_size;
    std::string ship_name;

    virtual void SpecialMove() = 0;
    std::string Get_Ship_Name()            {return ship_name;}
    std::vector<TILE_INFO> ship_info;
    void set_ship_tile(int x, int y,int IsHit, int ship_part);
private:

};
#endif
