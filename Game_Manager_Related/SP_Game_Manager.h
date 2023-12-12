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
      Game_Player Player_Me;
      AI_Player::First_AI Player_Enemy;
};


#endif //GAME_FROM_SCRATCH_AGAIN_SP_GAME_MANAGER_H
