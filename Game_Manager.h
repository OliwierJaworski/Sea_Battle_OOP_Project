#ifndef REMADE_SEA_BATTLE_GAME_MANAGER_H
#define REMADE_SEA_BATTLE_GAME_MANAGER_H

#include <vector>
#include <string>
#include <iostream>


#include "Game_Player.h"
#include "Tcp_Server_Socket.h"
#include "Tcp_Client_Socket.h"

class Game_Manager
{

    public:
//constructor | destructor
    Game_Manager();
    ~Game_Manager();
//public
    int Play_Game();
    void PlayTurns(int * playersturn);
    void set_Game_Type(int type)                                             {Game_Type=type;}
    int Ask_Game_Type();
    bool Start_Correct_Protocol();
    private:
//private
    int Game_Type;
    Tcp_Server_Socket * Server;
    Tcp_Client_Socket * Client;
    std::vector<Game_Player *> PlayerVector;
    void Init_Players();
    void Free_Alloc();
};


#endif
