//
// Created by oliwier-desktop on 9/12/23.
//

#ifndef REMADE_SEA_BATTLE_BOATS_PATROL_BOAT_H
#define REMADE_SEA_BATTLE_BOATS_PATROL_BOAT_H
#include "Game_Boats.h"

class Boats_Patrol_Boat :  public Game_Boats
{
public:
//constructor | destructor
    Boats_Patrol_Boat();
    ~Boats_Patrol_Boat(){};

//public
    void SpecialMove();
};
#endif //REMADE_SEA_BATTLE_BOATS_PATROL_BOAT_H
