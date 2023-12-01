#ifndef GAME_FROM_SCRATCH_AGAIN_MP_GAME_MANAGER_H
#define GAME_FROM_SCRATCH_AGAIN_MP_GAME_MANAGER_H

#include "SP_Game_Manager.h"
#include "../TCP_Connection/Tcp_Server_Socket.h"
#include "../TCP_Connection/Tcp_Client_Socket.h"
enum Connection_type{TCP_CLIENT, TCP_HOST};
class MP_Game_Manager
{
public:
    MP_Game_Manager();
    ~MP_Game_Manager()  =default;

    bool Play_Game() ;
private:
    std::unique_ptr<SBN::Tcp_Client_Socket> Client;
    std::unique_ptr<SBN::Tcp_Server_Socket> host;

    std::string Player_Input() ;
    void Init_TCP_Connection(int connection_type);
    int filter_input();
    void play_turn(Game_Player & Current_Player,Game_Player & Enemy_Player);
    bool Game_State_active() ;
};

#endif
