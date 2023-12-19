#ifndef REMADE_SEA_BATTLE_TCP_CLIENT_SOCKET_H
#define REMADE_SEA_BATTLE_TCP_CLIENT_SOCKET_H
#include "TCP_SHARED.h"

namespace SBN
{

    class Tcp_Client_Socket : public TCP_SHARED
    {
    public:
                 Tcp_Client_Socket(const std::string port_addr, const std::string device_addr);
                 ~Tcp_Client_Socket();

const inline int* get_socket_state() { return &internet_socket;}
    private:
             int initialization();
            void cleanup(int internet_socket);

             int internet_socket;
          struct addrinfo internet_address_setup;
          struct addrinfo *internet_address_result;
             int getaddrinfo_return;
          struct addrinfo *internet_address_result_iterator;
             int connect_return;
             int shutdown_return;
    };
}
#endif






















