#include "Boats_Destroyer.h"

Boats_Destroyer::Boats_Destroyer()
{
    set_Boat_name("destroyer");
    set_Boat_Size(2);
    Init_Boat_Tiles();
}


void Boats_Destroyer::SpecialMove()
{
    std::cout << "this Destroyer has no special move yet!" << std::endl;
}


