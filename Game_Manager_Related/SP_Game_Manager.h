#ifndef GAME_FROM_SCRATCH_AGAIN_SP_GAME_MANAGER_H
#define GAME_FROM_SCRATCH_AGAIN_SP_GAME_MANAGER_H

#include <iostream>
#include <memory>
#include <string>

#include "../Player_Related/Game_Player.h"
#include "../Player_Related/First_AI.h"

class SP_Game_Manager
{
public:
                  SP_Game_Manager()=default;
          virtual ~SP_Game_Manager()=default;
      Coordinates tranlate_to_cords(std::string input_string);

     virtual bool Play_Game();
protected:
     virtual bool Game_State_active();
private:
    //player gaat een template function moeten worden omdat elke speler andere grootte heeft enz
    std::vector<Game_Player *> player_vector;
    bool Player_Add_ToGame(Game_Player & curr_player, bool identical_players_allowed);
};

#endif
