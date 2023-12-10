#ifndef REMADE_SEA_BATTLE_GAME_PLAYER_H
#define REMADE_SEA_BATTLE_GAME_PLAYER_H
#include <string>
#include <memory>
#include "Game_Map.h"



class Game_Player
{
public:
               Game_Player()=default;
       virtual ~Game_Player() {std::cout << "destructor of game_player";}

          bool Get_Player_boats_alive();
          void Attack_Enemy(Game_Player & Enemy_Player,Coordinates User_Input_Cords);
   std::string Player_Input();
          void print_map();
protected:
      Game_Map map;
private:
};
#endif