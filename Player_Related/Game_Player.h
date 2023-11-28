#ifndef REMADE_SEA_BATTLE_GAME_PLAYER_H
#define REMADE_SEA_BATTLE_GAME_PLAYER_H
#include <string>
#include <memory>
#include "Game_Map.h"


class Game_Player
{
public:
    Game_Player()   {};
    virtual ~Game_Player()  {};

    virtual bool Get_Player_lost();
    virtual void Attack_Enemy();
    void print_map();


protected:
    Game_Map map;
};


#endif
