#include "Tcp_Client_Socket.h"

using namespace SBN;
Tcp_Client_Socket::Tcp_Client_Socket()
{
    #ifdef _WIN32
        OSInit();
    #endif
    internet_socket = initialization();
    send(internet_socket);
    recv(internet_socket);
}
Tcp_Client_Socket::~Tcp_Client_Socket()
{
    cleanup( internet_socket );
    #ifdef _WIN32
        OSCleanup();
    #endif
}

int Tcp_Client_Socket::initialization()
{
    memset( &internet_address_setup, 0, sizeof internet_address_setup );
    internet_address_setup.ai_family = AF_UNSPEC;
    internet_address_setup.ai_socktype = SOCK_STREAM;
    getaddrinfo_return = getaddrinfo( "192.168.0.145", "42661", &internet_address_setup, &internet_address_result );
    if( getaddrinfo_return != 0 )
    {
        fprintf( stderr, "getaddrinfo: %s\n", gai_strerror( getaddrinfo_return ) );
        exit( 1 );
    }

    internet_socket = -1;
    internet_address_result_iterator = internet_address_result;
    while( internet_address_result_iterator != NULL )
    {
        internet_socket = socket( internet_address_result_iterator->ai_family, internet_address_result_iterator->ai_socktype, internet_address_result_iterator->ai_protocol );
        if( internet_socket == -1 )
        {
            perror( "socket" );
        }
        else
        {
            //Step 1.3
            connect_return = connect( internet_socket, internet_address_result_iterator->ai_addr, internet_address_result_iterator->ai_addrlen );
            if( connect_return == -1 )
            {
                perror( "connect" );
                close( internet_socket );
            }
            else
            {
                break;
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
void Tcp_Client_Socket::recv( int internet_socket )
{
    {
        number_of_bytes_received = 0;
        char buffer[1000];
        number_of_bytes_received = ::recv( internet_socket, buffer, ( sizeof buffer ) - 1, 0 );
        if( number_of_bytes_received == -1 )
        {
            perror( "recv" );
        }
        else
        {
            buffer[number_of_bytes_received] = '\0';
            printf( "Received : %s\n", buffer );
        }
    }
}
void Tcp_Client_Socket::send( int internet_socket )
{
        number_of_bytes_send = 0;
        number_of_bytes_send = ::send( internet_socket, "Hello TCP world!", 16, 0 );
        if( number_of_bytes_send == -1 )
        {
            perror( "send" );
        }
}

void Tcp_Client_Socket::cleanup( int internet_socket )
{
#ifdef _WIN32
    shutdown_return = shutdown( internet_socket, SD_SEND );
#else
    shutdown_return = shutdown( internet_socket, SHUT_WR );
#endif
    if( shutdown_return == -1 )
    {
        perror( "shutdown" );
    }

    //Step 3.1
    close( internet_socket );
}