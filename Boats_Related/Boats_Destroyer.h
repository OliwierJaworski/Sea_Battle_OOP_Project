#ifndef REMADE_SEA_BATTLE_BOATS_DESTROYER_H
#define REMADE_SEA_BATTLE_BOATS_DESTROYER_H

#include "Game_Boats.h"

class Boats_Destroyer : public Game_Boats
{

public:

             Boats_Destroyer() : Game_Boats(3, "destroyer") {}
             ~Boats_Destroyer(){};


        void SpecialMove();
private:



};


#endif
