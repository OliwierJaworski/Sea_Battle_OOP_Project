//
// Created by oliwier-desktop on 9/12/23.
//

#include "Boats_Submarine.h"
Boats_Submarine::Boats_Submarine()
{
    set_Boat_name("Boats_Submarine");
    set_Boat_Size(3);
    Init_Boat_Tiles();
}

void Boats_Submarine::SpecialMove()
{
    std::cout << "this Boats_Submarine has no special move yet!" << std::endl;
}