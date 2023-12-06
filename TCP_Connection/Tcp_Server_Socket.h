#ifndef REMADE_SEA_BATTLE_TCP_SERVER_SOCKET_H
#define REMADE_SEA_BATTLE_TCP_SERVER_SOCKET_H
#include "../Player_Related/Game_Player.h"

#ifdef _WIN32
#define _WIN32_WINNT _WIN32_WINNT_WIN7
	#include <winsock2.h> //for all socket programming
	#include <ws2tcpip.h> //for getaddrinfo, inet_pton, inet_ntop
	#include <stdio.h> //for fprintf, perror
	#include <unistd.h> //for close
	#include <stdlib.h> //for exit
	#include <string.h> //for memset
    #include <iostream>
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

#include <sys/socket.h> //for sockaddr, socket, socket
#include <sys/types.h> //for size_t
#include <netdb.h> //for getaddrinfo
#include <netinet/in.h> //for sockaddr_in
#include <arpa/inet.h> //for htons, htonl, inet_pton, inet_ntop
#include <errno.h> //for errno
#include <stdio.h> //for fprintf, perror
#include <unistd.h> //for close
#include <stdlib.h> //for exit
#include <string.h> //for memset
#include <iostream>
#endif
#include <sstream>
#include "nlohmann/json.hpp"
namespace SBN//SEA_Battle_Networking
{
    struct MSG
    {
        int MSG_Type;
        int x;
        int y;
        bool bool_recvd;
        std::string message;
    };

    class Tcp_Server_Socket
    {
    public:

        struct TCP_DATA_FORMAT
        {
            int MSG_Type=10;//10 is niet gedeclared
            Coordinates var_cords;
            std::string var_string;
            bool recvd_bool;
        };

        Tcp_Server_Socket();
        ~Tcp_Server_Socket();
        void bind_to_client();
        std::string serialize(MSG& msgPacket);
        MSG deserialize(std::string & str);
        int get_Client_socket_state() { return client_internet_socket; }

    private:
        int initialization();
        int connection(int internet_socket);
        void recv(int internet_socket);
        void send(int internet_socket,std::string StringData_ToBe_send);
        void cleanup(int internet_socket, int client_internet_socket);
//main
        int internet_socket;
        int client_internet_socket;
//initialization
        struct addrinfo internet_address_setup;
        struct addrinfo *internet_address_result;
        int getaddrinfo_return;
        struct addrinfo *internet_address_result_iterator;
//connection
        struct sockaddr_storage client_internet_address;
        socklen_t client_internet_address_length;
        int client_socket;
//execution->recv
        int number_of_bytes_received;
//execution->send
        int number_of_bytes_send;
//cleanup
        int shutdown_return;
    };
}
#endif














