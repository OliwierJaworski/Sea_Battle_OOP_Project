#ifndef REMADE_SEA_BATTLE_SIMPLE_AI_H
#define REMADE_SEA_BATTLE_SIMPLE_AI_H

#include "Game_Player.h"

class Simple_Ai  : public Game_Player
{
public:
                Simple_Ai()=default;
                ~Simple_Ai()=default;
private:
    Coordinates Attack_Enemy() override;
};
#endif

