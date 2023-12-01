#include "Boats_Carrier.h"

Boats_Carrier::Boats_Carrier()
{
    set_Boat_name("Carrier");
    set_Boat_Size(5);
    Init_Boat_Tiles();
}

void Boats_Carrier::SpecialMove()
{
    std::cout << "this Carrier has no special move yet!" << std::endl;
}