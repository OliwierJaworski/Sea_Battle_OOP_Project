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
  Game_Player* get_player_id() {return this;}
   virtual Coordinates Attack_Enemy();
    Coordinates tranlate_to_cords(std::string input_string);
   std::string Player_Input();
          void print_map();
    inline Game_Map & Get_map_instance() {return  * map;}
protected:
   // inline Game_Map & Get_map_instance() {return  * map;}<----moet hier
private:
    Game_Map * map;//to prevent object slicing
};
#endif