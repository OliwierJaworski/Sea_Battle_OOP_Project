#ifndef GAME_FROM_SCRATCH_AGAIN_MP_GAME_MANAGER_H
#define GAME_FROM_SCRATCH_AGAIN_MP_GAME_MANAGER_H

#include "../TCP_Connection/Tcp_Server_Socket.h"
#include "../TCP_Connection/Tcp_Client_Socket.h"
#include "../Player_Related/Online_Player.h"

class MP_Game_Manager
{
                               friend class Game_Manager_Loader;
public:
                                            MP_Game_Manager();
                                            ~MP_Game_Manager()  =default;
                                       enum Connection_type
                                            {
                                            TCP_CLIENT,
                                            TCP_HOST
                                            };

private:
    std::unique_ptr<SBN::Tcp_Client_Socket> Client = nullptr;
    std::unique_ptr<SBN::Tcp_Server_Socket> host = nullptr;
                              Online_Player Player_Me;
                                       bool keepgamerolling=true;
                                std::string Player_Input_init() ;
                                        int filter_input();
                                       void Init_TCP_Connection(int connection_type);
                                       void host_play_turn();
                                       void client_play_turn();
                                 MSG_STRUCT Player_turn_decision(MSG_STRUCT recvd_content);
                                       void Play_Game();
};
#endif
