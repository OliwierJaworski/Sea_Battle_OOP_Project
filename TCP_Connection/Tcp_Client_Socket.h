#ifndef REMADE_SEA_BATTLE_TCP_CLIENT_SOCKET_H
#define REMADE_SEA_BATTLE_TCP_CLIENT_SOCKET_H
#include "TCP_SHARED.h"

namespace SBN
{

    class Tcp_Client_Socket : public TCP_SHARED
    {
    public:
                Tcp_Client_Socket();

                ~Tcp_Client_Socket();

             int get_socket_state() { return internet_socket;}
    private:
            enum change_received_data_to{Player_Array,Player_Cords};
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
//cleanup
             int shutdown_return;
    };
}
#endif






















