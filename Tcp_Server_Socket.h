#ifndef REMADE_SEA_BATTLE_TCP_SERVER_SOCKET_H
#define REMADE_SEA_BATTLE_TCP_SERVER_SOCKET_H



#include "Game_TCP_Communication.h"

class Tcp_Server_Socket : public Game_TCP_Communication
{
//public
public:
        Tcp_Server_Socket();
        ~Tcp_Server_Socket() override    {close_socket();}
        bool is_Client_Connected() {listen_for_connections();}
//private
private:
        int Create_Socket() override;
        bool Bind_to_port() override;
        bool listen_for_connections();
        bool close_socket() override;
};
#endif











