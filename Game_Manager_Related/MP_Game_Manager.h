#ifndef GAME_FROM_SCRATCH_AGAIN_MP_GAME_MANAGER_H
#define GAME_FROM_SCRATCH_AGAIN_MP_GAME_MANAGER_H

#include "SP_Game_Manager.h"
#include "../TCP_Connection/Tcp_Server_Socket.h"
#include "../TCP_Connection/Tcp_Client_Socket.h"
enum Connection_type{TCP_CLIENT, TCP_HOST};
enum  msg_prefix //maak class van als tijd over
        {
            DC  //DIRECTCHAT WITH OPONENT
           ,YT  //Transfer the turn to the other party

        };
class MP_Game_Manager
{
public:
    MP_Game_Manager();
    ~MP_Game_Manager()  =default;

    int Play_Game() ;
private:
    std::unique_ptr<SBN::Tcp_Client_Socket> Client = nullptr;
    std::unique_ptr<SBN::Tcp_Server_Socket> host = nullptr;
    Game_Player Player_Me;

    std::string Player_Input_init() ;
    void Init_TCP_Connection(int connection_type);
    int filter_input();
    void host_play_turn();
    void client_play_turn();
    bool Game_State_active() ;
    int Check_message_type(std::string message_received);

    template <typename Type_1>
    Type_1 convert_message_content(Type_1 message_received, int message_type);
};

#endif
