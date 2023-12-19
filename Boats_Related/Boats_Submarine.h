//
// Created by oliwier-desktop on 9/12/23.
//

#ifndef REMADE_SEA_BATTLE_BOATS_SUBMARINE_H
#define REMADE_SEA_BATTLE_BOATS_SUBMARINE_H
#include "Game_Boats.h"

class Boats_Submarine : public Game_Boats
{
public:

    Boats_Submarine() : Game_Boats(3, "Submarine") {}
    ~Boats_Submarine(){};


    void SpecialMove();
};
#endif //REMADE_SEA_BATTLE_BOATS_SUBMARINE_H
