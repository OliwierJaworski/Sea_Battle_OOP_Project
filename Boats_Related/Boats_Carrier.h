#ifndef REMADE_SEA_BATTLE_BOATS_CARRIER_H
#define REMADE_SEA_BATTLE_BOATS_CARRIER_H

#include "Game_Boats.h"

class Boats_Carrier  : public Game_Boats
{
public:

                Boats_Carrier() : Game_Boats(5, "Carrier") {}
                ~Boats_Carrier(){};


           void SpecialMove();
private:


};


#endif
