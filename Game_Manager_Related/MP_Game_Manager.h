#ifndef GAME_FROM_SCRATCH_AGAIN_MP_GAME_MANAGER_H
#define GAME_FROM_SCRATCH_AGAIN_MP_GAME_MANAGER_H

#include "SP_Game_Manager.h"
#include "../TCP_Connection/Tcp_Server_Socket.h"
#include "../TCP_Connection/Tcp_Client_Socket.h"

#include <type_traits>

enum Connection_type
        {
            TCP_CLIENT,
            TCP_HOST
        };
enum  msg_prefix //maak class van als tijd over
        {
            DM,  //DIRECTCHAT received from OPONENT
            YT,  //Transfer the turn to the other party
            AT   //attack received format: "AT,y.x"

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
    int filter_input();

    void Init_TCP_Connection(int connection_type);
    void host_play_turn();
    void client_play_turn();
    bool Game_State_active() ;

    int Check_message_type(std::string message_received);
    std::string Player_turn_decision();
    template<typename MSG_TYPE>
    typename std::conditional<std::is_same<MSG_TYPE, std::string>::value, std::string ,Coordinates>::type Convert_Message(std::string recvd_message,int msg_type);
};

#endif
