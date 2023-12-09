//
// Created by oliwier-desktop on 9/12/23.
//

#ifndef REMADE_SEA_BATTLE_BOATS_BATTLESHIP_H
#define REMADE_SEA_BATTLE_BOATS_BATTLESHIP_H
#include "Game_Boats.h"

class Boats_Battleship : public Game_Boats
{
public:
//constructor | destructor
    Boats_Battleship() : Game_Boats(4, "Battleship") {}
    ~Boats_Battleship() {};

//public
    void SpecialMove();
};
#endif //REMADE_SEA_BATTLE_BOATS_BATTLESHIP_H
