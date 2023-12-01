#include "Boats_Carrier.h"

Boats_Carrier::Boats_Carrier()
{
    ship_name = "Carrier";
    Boat_size =5;
}

void Boats_Carrier::SpecialMove()
{
    std::cout << "this Carrier has no special move yet!" << std::endl;
}