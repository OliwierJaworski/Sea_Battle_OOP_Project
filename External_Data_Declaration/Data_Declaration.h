#ifndef REMADE_SEA_BATTLE_DATA_DECLARATION_H
#define REMADE_SEA_BATTLE_DATA_DECLARATION_H
#include "../Boats_Related/Game_Boats.h"

enum TILE_STATE {
                 MISS,
                 HIT,
                 SHIP
                };

struct TILE_INFO
{
    int x;//cords of part of ship
    int y;
    int IsHit = MISS;
    const std::shared_ptr<Game_Boats> ship_on_tile = nullptr;//easier way to iterate through ships
};

#endif //REMADE_SEA_BATTLE_DATA_DECLARATION_H
