#ifndef REMADE_SEA_BATTLE_TCP_SERVER_SOCKET_H
#define REMADE_SEA_BATTLE_TCP_SERVER_SOCKET_H



#include "Game_TCP_Communication.h"

class Tcp_Server_Socket : public Game_TCP_Communication
{

public:
//public
//constructor | destructor
    Tcp_Server_Socket();
    ~Tcp_Server_Socket() override    {close_socket();}

//Tcp_Server_Socket Core structure

//extra added functionality
    bool set_connection(Tcp_Server_Socket& server);
    bool get_Connection_Bind() {return Connection_Bind;}

private:
//private
//Tcp_Server_Socket Core structure
    int Create_Socket() override;
    bool Bind_to_port() override;
    bool listen_for_connections();

//extra added functionality
        bool Connection_Bind;

//initialization & destruction
        bool close_socket() override;
};
#endif











