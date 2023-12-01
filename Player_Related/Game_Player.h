#ifndef REMADE_SEA_BATTLE_GAME_PLAYER_H
#define REMADE_SEA_BATTLE_GAME_PLAYER_H
#include <string>
#include <memory>
#include "Game_Map.h"


class Game_Player
{
public:
    Game_Player() {std::cout <<"Player object is created in SP";}
    virtual ~Game_Player();

    virtual bool Get_Player_lost();
    virtual void Attack_Enemy(Game_Player & Enemy_Player);
    bool Verify_Ifenemy_Hit(int y, int x)           {return map.get_my_map(y,x);}
    void print_map();

protected:
    Game_Map map;
};
#endif