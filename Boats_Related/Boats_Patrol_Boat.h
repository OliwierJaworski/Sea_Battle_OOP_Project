//
// Created by oliwier-desktop on 9/12/23.
//

#ifndef REMADE_SEA_BATTLE_BOATS_PATROL_BOAT_H
#define REMADE_SEA_BATTLE_BOATS_PATROL_BOAT_H
#include "Game_Boats.h"

class Boats_Patrol_Boat :  public Game_Boats
{
public:

    Boats_Patrol_Boat() : Game_Boats(2, "Patrol_Boat") {}
    ~Boats_Patrol_Boat(){};


    void SpecialMove();
};
#endif //REMADE_SEA_BATTLE_BOATS_PATROL_BOAT_H
