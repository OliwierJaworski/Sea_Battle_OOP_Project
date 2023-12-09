//
// Created by oliwier-desktop on 9/12/23.
//

#ifndef REMADE_SEA_BATTLE_BOATS_SUBMARINE_H
#define REMADE_SEA_BATTLE_BOATS_SUBMARINE_H
#include "Game_Boats.h"

class Boats_Submarine : public Game_Boats
{
public:
//constructor | destructor
    Boats_Submarine() : Game_Boats(3, "Submarine") { Init_Boat_Tiles();}
    ~Boats_Submarine(){};

//public
    void SpecialMove();
};
#endif //REMADE_SEA_BATTLE_BOATS_SUBMARINE_H
