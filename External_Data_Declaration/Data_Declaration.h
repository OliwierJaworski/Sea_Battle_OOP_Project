#ifndef REMADE_SEA_BATTLE_DATA_DECLARATION_H
#define REMADE_SEA_BATTLE_DATA_DECLARATION_H
#include "../Boats_Related/Game_Boats.h.h"

enum TILE_STATE {
                 MISS,
                 HIT,
                 SHIP,
                 WATER
                };
enum Rotation_Direction {
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
    //std::shared_ptr<> ship_on_tile = nullptr;//easier way to iterate through ships
};

#endif //REMADE_SEA_BATTLE_DATA_DECLARATION_H
