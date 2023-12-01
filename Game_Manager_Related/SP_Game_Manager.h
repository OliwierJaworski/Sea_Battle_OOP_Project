#ifndef GAME_FROM_SCRATCH_AGAIN_SP_GAME_MANAGER_H
#define GAME_FROM_SCRATCH_AGAIN_SP_GAME_MANAGER_H

#include <iostream>
#include <memory>
#include <string>
#include "../Player_Related/Game_Player.h"


class SP_Game_Manager
{
public:
    SP_Game_Manager() ;
    virtual ~SP_Game_Manager();

    std::string Player_Input();//x,y||chat"hey blabla"
    Coordinates tranlate_to_cords(std::string input_string);

protected:
    virtual bool Play_Game();
    virtual void play_turn(Game_Player & Current_Player,Game_Player & Enemy_Player);
    virtual bool Game_State_active();
private:
    Game_Player Player_Me;
    Game_Player Player_Enemy;
};


#endif //GAME_FROM_SCRATCH_AGAIN_SP_GAME_MANAGER_H
