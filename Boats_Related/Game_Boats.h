#ifndef REMADE_SEA_BATTLE_GAME_BOATS_H
#define REMADE_SEA_BATTLE_GAME_BOATS_H

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "../External_Data_Declaration/Data_Declaration.h"

class Game_Boats
{

public:
//constructor | destructor
    Game_Boats() : size(0) {}
    virtual ~Game_Boats() {};
//public
    virtual void SpecialMove() = 0;
    int Get_Size()                                                                               {return size;}
private:
//private

protected:
//protected
    int size;
    std::string ship_name;
    std::vector<TILE_INFO> ship_info;

};


#endif
