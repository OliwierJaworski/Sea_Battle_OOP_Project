#ifndef REMADE_SEA_BATTLE_TCP_CLIENT_SOCKET_H
#define REMADE_SEA_BATTLE_TCP_CLIENT_SOCKET_H

#include "Game_TCP_Communication.h"

class Tcp_Client_Socket : public Game_TCP_Communication
{
    friend class Game_Manager;

public:
//public
//constructor | destructor
    Tcp_Client_Socket();
    ~Tcp_Client_Socket() override            {close_socket();}

//Boats_Carrier Core structure
//extra added functionality
    void set_IP(std::string IP_New)          {IP=IP_New;}
    void set_PORT(int PORT_New)              {Used_Port=52100;}//{Used_Port=PORT_New;}
    const char* return_IP()                  {return ipAddress;}


private:
//private
//Boats_Carrier Core structure
    int status;
    struct sockaddr_in serv_addr;
    char buffer[1024] = { 0 };
    const char*  ipAddress =IP.c_str();

    int  Create_Socket() override;
    bool Bind_to_port() override;
    bool Connect_to_Server();

//extra added functionality
    std::string IP = "192.168.0.145";

//initialization & destruction
    bool close_socket() override;
};
#endif















