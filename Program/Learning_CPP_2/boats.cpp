#include "boats.h"

Carrier::Carrier(int size, std::string name)
{
    boatsize = size;
    boatname = name;
}
//---------------------------------------------------
Submarine::Submarine(int size, std::string name)
{
    boatsize = size;
}
//---------------------------------------------------
Battleship::Battleship(int size, std::string name)
{
    boatsize = size;
}
//---------------------------------------------------
Cruiser::Cruiser(int size, std::string name)
{
    boatsize = size;
}
//---------------------------------------------------
Destroyer::Destroyer(int size, std::string name)
{
    boatsize = size;
    boatname = name;
}
//---------------------------------------------------
