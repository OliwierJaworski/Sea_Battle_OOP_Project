#include "Game_Boats.h"

#ifndef REMADE_SEA_BATTLE_BOATS_CARRIER_H
#define REMADE_SEA_BATTLE_BOATS_CARRIER_H


class Boats_Carrier  : public Game_Boats
{
public:
//constructor | destructor
    Boats_Carrier();
    ~Boats_Carrier(){};

//public
    void SpecialMove();
private:
//private

};


#endif