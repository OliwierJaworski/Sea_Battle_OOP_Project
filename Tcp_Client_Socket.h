#ifndef REMADE_SEA_BATTLE_TCP_CLIENT_SOCKET_H
#define REMADE_SEA_BATTLE_TCP_CLIENT_SOCKET_H
#ifdef _WIN32
#define _WIN32_WINNT _WIN32_WINNT_WIN7
	#include <winsock2.h> //for all socket programming
	#include <ws2tcpip.h> //for getaddrinfo, inet_pton, inet_ntop
	#include <stdio.h> //for fprintf, perror
	#include <unistd.h> //for close
	#include <stdlib.h> //for exit
	#include <string.h> //for memset
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
#endif
namespace SBN
{
    class Tcp_Client_Socket
    {
    public:
        Tcp_Client_Socket();

        ~Tcp_Client_Socket();

        void recv(int internet_socket);
        void send(int internet_socket);

        int get_internet_socket() { return internet_socket;}

    private:
        int initialization();

        void cleanup(int internet_socket);

//main
        int internet_socket;
//initialization
        struct addrinfo internet_address_setup;
        struct addrinfo *internet_address_result;
        int getaddrinfo_return;
        struct addrinfo *internet_address_result_iterator;
        int connect_return;
//execution recv
        int number_of_bytes_send;
//execution send
        int number_of_bytes_received;
//cleanup
        int shutdown_return;
    };
}
#endif






















