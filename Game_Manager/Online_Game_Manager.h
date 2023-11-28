#ifndef REMADE_SEA_BATTLE_ONLINE_GAME_MANAGER_H
#define REMADE_SEA_BATTLE_ONLINE_GAME_MANAGER_H

#include "Game_Manager.h"

class Online_Game_Manager : public Game_Manager
{
public:
    Online_Game_Manager() ;
    ~Online_Game_Manager() override;

    bool Play_Game() override;
private:
    Game_Player me_the_player;
};

#endif
