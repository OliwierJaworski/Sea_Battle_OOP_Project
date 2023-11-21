#ifndef REMADE_SEA_BATTLE_GAME_TCP_COMMUNICATION_H
#define REMADE_SEA_BATTLE_GAME_TCP_COMMUNICATION_H

#ifdef _WIN32
#define _WIN32_WINNT _WIN32_WINNT_WIN7

#include <sys/socket.h> // for sockaddr, socket, socket
#include <sys/types.h>   // for size_t
#include <netdb.h>       // for getaddrinfo
#include <netinet/in.h>  // for sockaddr_in
#include <arpa/inet.h>   // for htons, htonl, inet_pton, inet_ntop
#include <cerrno>        // for errno (C++ version)
#include <cstdio>        // for fprintf
#include <unistd.h>      // for close
#include <cstdlib>       // for exit
#include <cstring>       // for memset (C++ version)
#include <ctime>         // for time_t, struct tm
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <thread>

void OSInit( void )
{
    WSADATA wsaData;
    int WSAError = WSAStartup( MAKEWORD( 2, 0 ), &wsaData );
    if( WSAError != 0 )
    {
        fprintf( stderr, "WSAStartup errno = %d\n", WSAError );
        exit( -1 );
    }
}
void OSCleanup( void )
{
    WSACleanup();
}
#define perror(string) fprintf( stderr, string ": WSA errno = %d\n", WSAGetLastError() )
#else

#include <sys/socket.h>    // for sockaddr, socket, socket
#include <sys/types.h>      // for size_t
#include <netdb.h>          // for getaddrinfo
#include <netinet/in.h>     // for sockaddr_in
#include <arpa/inet.h>      // for htons, htonl, inet_pton, inet_ntop
#include <cerrno>           // for errno (C++ version)
#include <cstdio>           // for fprintf
#include <unistd.h>         // for close
#include <cstdlib>          // for exit
#include <cstring>          // for memset (C++ version)
#include <ctime>            // for time_t, struct tm
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <thread>
#endif




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
