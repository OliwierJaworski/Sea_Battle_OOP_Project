#ifndef REMADE_SEA_BATTLE_ONLINE_PLAYER_H
#define REMADE_SEA_BATTLE_ONLINE_PLAYER_H

#include "Game_Player.h"
class Online_Player : public Game_Player
{
public:
    Online_Player() {};
    ~Online_Player() override {};

     bool Get_Player_lost()  override;
     void Attack_Enemy() override;
private:
};


#endif
