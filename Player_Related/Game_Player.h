#ifndef REMADE_SEA_BATTLE_GAME_PLAYER_H
#define REMADE_SEA_BATTLE_GAME_PLAYER_H
#include <string>
#include <memory>
#include "Game_Map.h"



class Game_Player
{
public:
             Game_Player();
    virtual  ~Game_Player();

        bool Get_Player_boats_alive();
        void Attack_Enemy(Game_Player & Enemy_Player,Coordinates User_Input_Cords);
        std::string Player_Input();
        void print_map(int whichmap);
protected:
    Game_Map get_map(){return  map;}
private:
    Game_Map map;
};
#endif