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
friend class Game_Map;
public:
//constructor | destructor
    Game_Boats() : Boat_size(0){ship_info.size()=Boat_size;}
    virtual ~Game_Boats() {};

    int Get_Size()                         {return Boat_size;}

protected:
    int Boat_size;
    std::string ship_name;
    std::vector<TILE_INFO> ship_info;

    virtual void SpecialMove() = 0;
    std::string Get_Ship_Name()            {return ship_name;}
    void set_ship_tile(int x, int y,int IsHit, int ship_part);
    TILE_INFO * Get_ship_tile(int i)    {return & ship_info.at(i);}

private:

};


#endif
