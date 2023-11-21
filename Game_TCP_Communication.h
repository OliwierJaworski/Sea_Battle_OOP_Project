#ifndef REMADE_SEA_BATTLE_GAME_TCP_COMMUNICATION_H
#define REMADE_SEA_BATTLE_GAME_TCP_COMMUNICATION_H

#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <thread>

class Game_TCP_Communication
{
public:
//constructor | destructor
    virtual ~Game_TCP_Communication()=0;
//public
//Game_TCP_Communication Core structure
    void send_data(std::string inputmessage);
    void recv_data();
//extra added functionality
    int get_port() {return Used_Port;}

protected:
//protected
//Game_TCP_Communication Core structure
    int server_client_fd, new_socket;
    int Used_Port =18754;
    int opt = 1;

    std::string message;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    ssize_t valread;

    virtual int Create_Socket()=0;
    virtual bool Bind_to_port()=0;
    virtual bool close_socket()=0;
    char  buffer[1024] = { 0 };
//extra added functionality

    /*-> "context" :: to give the ip of person connected to you, will be implemented in later version
      ->"function" :: char * ip =inet_ntoa(their_addr.sin_addr)*/


};


#endif //REMADE_SEA_BATTLE_GAME_TCP_COMMUNICATION_H
