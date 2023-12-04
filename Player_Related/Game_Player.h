#ifndef REMADE_SEA_BATTLE_GAME_PLAYER_H
#define REMADE_SEA_BATTLE_GAME_PLAYER_H
#include <string>
#include <memory>
#include "Game_Map.h"

 struct Coordinates
{
    int x;
    int y;
};

class Game_Player
{
public:
    Game_Player() {std::cout <<"Player object is created in SP"<< std::endl;}
    virtual ~Game_Player();

    bool Get_Player_boats_alive();
    virtual void Attack_Enemy(Game_Player & Enemy_Player,Coordinates User_Input_Cords);
    bool Verify_Ifenemy_Hit(int y, int x)           {return map.get_my_map(y,x);}
    void print_map(int whichmap);

protected:
    Game_Map map;
};
#endif