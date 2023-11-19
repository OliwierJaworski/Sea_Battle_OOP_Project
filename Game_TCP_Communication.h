#ifndef REMADE_SEA_BATTLE_GAME_TCP_COMMUNICATION_H
#define REMADE_SEA_BATTLE_GAME_TCP_COMMUNICATION_H

#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>

class Game_TCP_Communication
{
//public
public:
    virtual ~Game_TCP_Communication()=0;
    void send_data();
    void recv_data();
    int get_port() {return Used_Port;}

//private
protected:
    virtual int Create_Socket()=0;
    virtual bool Bind_to_port()=0;
    virtual bool close_socket()=0;

    int server_client_fd, new_socket;
    int Used_Port =18754;
    int opt = 1;

    std::string message;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    ssize_t valread;

    //char * ip =inet_ntoa(their_addr.sin_addr)-> to give the ip of person connected to you
    char  buffer[1024] = { 0 };
};


#endif //REMADE_SEA_BATTLE_GAME_TCP_COMMUNICATION_H
