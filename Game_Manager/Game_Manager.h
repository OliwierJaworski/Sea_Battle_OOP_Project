#ifndef REMADE_SEA_BATTLE_GAME_MANAGER_H
#define REMADE_SEA_BATTLE_GAME_MANAGER_H

#include <vector>
#include <string>
#include <iostream>

#include "../Player_Related/Game_Player.h"
#include "../Tcp_Related/Tcp_Client_Socket.h"
#include "../Tcp_Related/Tcp_Server_Socket.h"


class Game_Manager
{
public:
    Game_Manager();
    virtual ~Game_Manager();

    virtual bool Play_Game();
    virtual bool Is_Game_Finished();
protected:

private:
    std::vector<std::unique_ptr<Game_Player>> PlayerVector;
    virtual void Init_Players();
};

#endif
