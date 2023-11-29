#ifndef REMADE_SEA_BATTLE_GAME_BOATS_H
#define REMADE_SEA_BATTLE_GAME_BOATS_H

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "../External_Data_Declaration/Data_Declaration.h"
#include "../Player_Related/Game_Map.h"

class Game_Boats
{
friend Game_Map;
public:
//constructor | destructor
    Game_Boats() : size(0) {}
    virtual ~Game_Boats() {};
//public
    virtual void SpecialMove() = 0;
    int Get_Size()                         {return size;}
    std::string Get_Ship_Name()            {return ship_name;}
    std::vector<TILE_INFO> Get_ship_tile(int i)    {return ship_info[i];}
private:
//private
    void set_ship_tile(int x, int y,int IsHit, )
protected:
//protected
    int size;
    std::string ship_name;
    std::vector<std::vector<TILE_INFO>> ship_info;
};


#endif
