#ifndef REMADE_SEA_BATTLE_GAME_PLAYER_H
#define REMADE_SEA_BATTLE_GAME_PLAYER_H
#include <string>
#include <memory>
#include "Game_Map.h"



class Game_Player
{
public:
               Game_Player() {map =new Game_Map;}
       virtual ~Game_Player() {delete map;}

          bool Get_Player_boats_alive();
          void Attack_Enemy(Game_Player & Enemy_Player,Coordinates User_Input_Cords);
   std::string Player_Input();
          void print_map();
protected:
    inline Game_Map & Get_map_instance() {return  * map;}
private:
    Game_Map * map;//to prevent object slicing
};
#endif