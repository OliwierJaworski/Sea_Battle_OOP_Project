#include "Boats_Battleship.h"
Boats_Battleship::Boats_Battleship()
{
    set_Boat_name("Boats_Battleship");
    set_Boat_Size(3);
    Init_Boat_Tiles();
}

void Boats_Battleship::SpecialMove()
{
    std::cout << "this Boats_Battleship has no special move yet!" << std::endl;
}