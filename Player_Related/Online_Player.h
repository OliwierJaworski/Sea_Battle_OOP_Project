#ifndef REMADE_SEA_BATTLE_ONLINE_PLAYER_H
#define REMADE_SEA_BATTLE_ONLINE_PLAYER_H

#include "Game_Player.h"
class Online_Player : public Game_Player
{
public:
    Online_Player() =default;
    ~Online_Player() override {};

    Coordinates Attack_Enemy(Coordinates User_Input_Cords);
    void Att_tile_state(Coordinates User_Input_Cords , bool Tile_State);
private:
};


#endif