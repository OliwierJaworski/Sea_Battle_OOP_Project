#ifndef REMADE_SEA_BATTLE_BOATS_BATTLESHIP_H
#define REMADE_SEA_BATTLE_BOATS_BATTLESHIP_H
#include "Game_Boats.h"

class Boats_Battleship : public Game_Boats
{
public:

    Boats_Battleship() : Game_Boats(4, "Battleship") {}
    ~Boats_Battleship() {};
    void SpecialMove();
};
#endif
