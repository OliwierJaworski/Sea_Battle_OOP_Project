#ifndef REMADE_SEA_BATTLE_GAME_MANAGER_H
#define REMADE_SEA_BATTLE_GAME_MANAGER_H

#include <vector>
#include <string>
#include <iostream>

#include "Game_Player.h"

class Game_Manager
{

    public:
//constructor | destructor
    Game_Manager();
    ~Game_Manager();
//public
    Game_Player* Get_Player_ID(int requested_id);
    int Play_Game();

    private:
//private
    std::vector<Game_Player *> PlayerVector;
    void Init_Players();
    void Free_Alloc();
};


#endif
