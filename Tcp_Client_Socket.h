#ifndef REMADE_SEA_BATTLE_TCP_CLIENT_SOCKET_H
#define REMADE_SEA_BATTLE_TCP_CLIENT_SOCKET_H

#include "Game_TCP_Communication.h"

class Tcp_Client_Socket : public Game_TCP_Communication
{
//public
public:
    Tcp_Client_Socket();
    ~Tcp_Client_Socket() override;
//private
private:
    int status;
    struct sockaddr_in serv_addr;
    char buffer[1024] = { 0 };
    std::string IP = "192.168.0.145";
    const char*  ipAddress =IP.c_str();

    int  Create_Socket() override;
    bool Bind_to_port() override;
    bool Connect_to_Server();
    bool close_socket() override;
};


#endif















