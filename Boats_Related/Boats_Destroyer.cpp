#include "Boats_Destroyer.h"

Boats_Destroyer::Boats_Destroyer()
{
    ship_name = "Destroyer";
    Boat_size = 2;
}


void Boats_Destroyer::SpecialMove()
{
    std::cout << "this Destroyer has no special move yet!" << std::endl;
}


