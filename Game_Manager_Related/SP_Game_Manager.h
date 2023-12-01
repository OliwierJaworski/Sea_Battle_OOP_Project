#ifndef GAME_FROM_SCRATCH_AGAIN_SP_GAME_MANAGER_H
#define GAME_FROM_SCRATCH_AGAIN_SP_GAME_MANAGER_H

#include <iostream>
#include <memory>
#include <string>
#include "../Player_Related/Game_Player.h"
class SP_Game_Manager
{
public:
    SP_Game_Manager() {std::cout << "SP constructor";}
    virtual ~SP_Game_Manager();
    virtual void attack_enemy();
    std::string Player_Input();//x,y||chat"hey blabla"
    bool Correct_Input_type(std::string user_input);
protected:
    virtual bool Play_Game();
    virtual bool Game_State();
private:
    Game_Player Player_Me;
    Game_Player Player_Enemy;
};


#endif //GAME_FROM_SCRATCH_AGAIN_SP_GAME_MANAGER_H
