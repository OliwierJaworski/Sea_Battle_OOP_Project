//
// Created by oliwier-desktop on 9/12/23.
//

#include "Boats_Patrol_Boat.h"
Boats_Patrol_Boat::Boats_Patrol_Boat()
{
    set_Boat_name("Boats_Patrol_Boat");
    set_Boat_Size(2);
    Init_Boat_Tiles();
}

void Boats_Patrol_Boat::SpecialMove()
{
    std::cout << "this Boats_Patrol_Boat has no special move yet!" << std::endl;
}