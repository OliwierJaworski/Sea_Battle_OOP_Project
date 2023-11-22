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

void OSInit( void ) {}
void OSCleanup( void ) {}
#endif
int initialization();
int connection( int internet_socket );
void execution( int internet_socket );
void cleanup( int internet_socket, int client_internet_socket );

int main( int argc, char * argv[] )
{
    //////////////////
    //Initialization//
    //////////////////

    OSInit();

    int internet_socket = initialization();

    //////////////
    //Connection//
    //////////////

    int client_internet_socket = connection( internet_socket );

    /////////////
    //Execution//
    /////////////

    execution( client_internet_socket );


    ////////////
    //Clean up//
    ////////////

    cleanup( internet_socket, client_internet_socket );

    OSCleanup();

    return 0;
}

int initialization()
{
    //Step 1.1
    struct addrinfo internet_address_setup;
    struct addrinfo * internet_address_result;
    memset( &internet_address_setup, 0, sizeof internet_address_setup );
    internet_address_setup.ai_family = AF_UNSPEC;
    internet_address_setup.ai_socktype = SOCK_STREAM;
    internet_address_setup.ai_flags = AI_PASSIVE;
    int getaddrinfo_return = getaddrinfo( NULL, "24042", &internet_address_setup, &internet_address_result );
    if( getaddrinfo_return != 0 )
    {
        fprintf( stderr, "getaddrinfo: %s\n", gai_strerror( getaddrinfo_return ) );
        exit( 1 );
    }

    int internet_socket = -1;
    struct addrinfo * internet_address_result_iterator = internet_address_result;
    while( internet_address_result_iterator != NULL )
    {
        //Step 1.2
        internet_socket = socket( internet_address_result_iterator->ai_family, internet_address_result_iterator->ai_socktype, internet_address_result_iterator->ai_protocol );
        if( internet_socket == -1 )
        {
            perror( "socket" );
        }
        else
        {
            //Step 1.3
            int bind_return = bind( internet_socket, internet_address_result_iterator->ai_addr, internet_address_result_iterator->ai_addrlen );
            if( bind_return == -1 )
            {
                perror( "bind" );
                close( internet_socket );
            }
            else
            {
                //Step 1.4
                int listen_return = listen( internet_socket, 1 );
                if( listen_return == -1 )
                {
                    close( internet_socket );
                    perror( "listen" );
                }
                else
                {
                    break;
                }
            }
        }
        internet_address_result_iterator = internet_address_result_iterator->ai_next;
    }

    freeaddrinfo( internet_address_result );

    if( internet_socket == -1 )
    {
        fprintf( stderr, "socket: no valid socket address found\n" );
        exit( 2 );
    }

    return internet_socket;
}

int connection( int internet_socket )
{
    //Step 2.1
    struct sockaddr_storage client_internet_address;
    socklen_t client_internet_address_length = sizeof client_internet_address;
    int client_socket = accept( internet_socket, (struct sockaddr *) &client_internet_address, &client_internet_address_length );
    if( client_socket == -1 )
    {
        perror( "accept" );
        close( internet_socket );
        exit( 3 );
    }
    return client_socket;
}

void execution( int internet_socket )
{
    //Step 3.1
    int number_of_bytes_received = 0;
    char buffer[1000];
    number_of_bytes_received = recv( internet_socket, buffer, ( sizeof buffer ) - 1, 0 );
    if( number_of_bytes_received == -1 )
    {
        perror( "recv" );
    }
    else
    {
        buffer[number_of_bytes_received] = '\0';
        printf( "Received : %s\n", buffer );
    }

    //Step 3.2
    int number_of_bytes_send = 0;
    number_of_bytes_send = send( internet_socket, "Hello TCP world!", 16, 0 );
    if( number_of_bytes_send == -1 )
    {
        perror( "send" );
    }
}

void cleanup( int internet_socket, int client_internet_socket )
{
    //Step 4.2
    int shutdown_return = shutdown( client_internet_socket, SHUT_RD );
    if( shutdown_return == -1 )
    {
        perror( "shutdown" );
    }

    //Step 4.1
    close( client_internet_socket );
    close( internet_socket );
}
