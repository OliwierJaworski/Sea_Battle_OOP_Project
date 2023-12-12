#ifndef REMADE_SEA_BATTLE_TILE_INFO_H
#define REMADE_SEA_BATTLE_TILE_INFO_H
#include "First_AI.h"
namespace AI_Player
{
    class tile_info
       {
        public:
               struct AI_Coordinates : Coordinates
                      {
                         int x = 0;
                         int y = 0;
                      };
               struct fit_direction
                      {
                         bool curr_dir_boat_fit =true;
                         int to_right=0;
                         int to_left=0;
                         int up=0;
                         int down=0;
                         int middle=0;
                      };
  const         float get_chance_ratio() {return chance_ratio;}
  const           int get_ships_alive(int ship_of_array) {return ships_alive[ship_of_array];}
  const fit_direction get_fit_direction() {return boat_dir_fits;}
  const           int get_direction_sum() {return direction_sum;}

                 void set_chance_ratio(float ratio) {chance_ratio =ratio;}
                 void set_ship_alive(int ship_chosen,int ship_state){ships_alive[ship_chosen]=ship_state;}
                 void set_fit_direction(fit_direction fit_type) {boat_dir_fits=fit_type;}
                 void set_direction_sum(float dir_sum) {direction_sum =dir_sum;}

        private:
                float chance_ratio = 0;//min 0 - max 100
        fit_direction boat_dir_fits;
                  int ships_alive[5] = {TILE_STATE::WATER};//shipsize
                float direction_sum=0;//updates depending on how many tiles a ship has been spotted
    };
}
using AI_Coordinates = AI_Player::tile_info::AI_Coordinates;

#endif //REMADE_SEA_BATTLE_TILE_INFO_H
