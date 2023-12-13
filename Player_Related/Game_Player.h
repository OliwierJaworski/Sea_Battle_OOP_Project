#ifndef REMADE_SEA_BATTLE_GAME_PLAYER_H
#define REMADE_SEA_BATTLE_GAME_PLAYER_H
#include <string>
#include <memory>
#include "Game_Map.h"

class Game_Player
{
       friend class SP_Game_Manager;
       friend class MP_Game_Manager;
public:
                    Game_Player() {map =new Game_Map;}
            virtual ~Game_Player() {delete map;}
protected:
         const bool Get_Player_boats_alive();
       Game_Player* get_player_id() {return this;}
virtual Coordinates Attack_Enemy();
        Coordinates tranlate_to_cords(std::string input_string);
        std::string Player_Input();
         const void print_map();
          Game_Map& Get_map_instance() {return  * map;}
private:
          Game_Map* map;//to prevent object slicing
};
#endif