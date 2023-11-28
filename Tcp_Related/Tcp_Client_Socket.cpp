#include "Tcp_Client_Socket.h"

using namespace SBN;
Tcp_Client_Socket::Tcp_Client_Socket()
{
    #ifdef _WIN32
        OSInit();
    #endif
    internet_socket = initialization();
    send(internet_socket,"Game Connect Request");
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
    getaddrinfo_return = getaddrinfo( "192.168.0.145", "24042", &internet_address_setup, &internet_address_result );
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
void Tcp_Client_Socket::send( int internet_socket, std::string StringData_ToBe_send)
{
        number_of_bytes_send = 0;
        number_of_bytes_send = ::send( internet_socket, StringData_ToBe_send.c_str(), StringData_ToBe_send.size(), 0 );
        if( number_of_bytes_send == -1 )
        {
            perror( "send" );
        }
}
/*
template <typename Not_Set_Datatype>
Not_Set_Datatype Tcp_Client_Socket::data_translation(int clarify_datatype)
{
    switch (clarify_datatype)
    {
        case Player_Array:
            int Tcp_Received_Array[10][10];
            std::istringstream iss(buffer);
            for (int i = 0; i < 9; ++i)
            {
                for (int j = 0; j < 9; ++j)
                {
                    iss >> Tcp_Received_Array[i][j];
                }
            }
            return Tcp_Received_Array;
            break;
        //case Player_Cords:

    }
}
*/
//template <typename Not_Set_Datatype>
std::vector<std::vector<int>> Tcp_Client_Socket::Get_Array_Format(int clarify_datatype)
{
    switch (clarify_datatype)
    {
        case Player_Array:
            std::vector<std::vector<int>> Tcp_Received_Array(10,std::vector<int>(10));
            int index=0;
            for (int i = 0; i < 10; ++i)
            {
                std::string char_to_int;
                char_to_int =buffer;
                for (int j = 0; j < 10; ++j)
                {
                    Tcp_Received_Array[i][j]= char_to_int[index]-'0';
                    index++;
                }
            }
            return Tcp_Received_Array;
            break;
            //case Player_Cords:

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




