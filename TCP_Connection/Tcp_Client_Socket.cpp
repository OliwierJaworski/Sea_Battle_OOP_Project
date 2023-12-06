#include "Tcp_Client_Socket.h"

using namespace SBN;
Tcp_Client_Socket::Tcp_Client_Socket()
{
    #ifdef _WIN32
        OSInit();
    #endif
    internet_socket = initialization();
    send(get_socket_state(), serialize_Tostring(default_message()));
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
    getaddrinfo_return = getaddrinfo( "192.168.0.185", "24042", &internet_address_setup, &internet_address_result );
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
MSG_STRUCT Tcp_Client_Socket::default_message()
{
    MSG_STRUCT msg;
    msg.MSG_Type=MSG_TYPE::YT;
    msg.bool_recvd= true;
    return msg;
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




