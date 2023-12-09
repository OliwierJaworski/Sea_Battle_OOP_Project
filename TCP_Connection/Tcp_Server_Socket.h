#ifndef REMADE_SEA_BATTLE_TCP_SERVER_SOCKET_H
#define REMADE_SEA_BATTLE_TCP_SERVER_SOCKET_H
#include "TCP_SHARED.h"

namespace SBN//SEA_Battle_Networking
{

    class Tcp_Server_Socket : public TCP_SHARED
    {
    public:
                   Tcp_Server_Socket(const std::string port_addr) : TCP_SHARED(port_addr,"127.0.0.1") {bind_to_client();}
                   ~Tcp_Server_Socket();
              void bind_to_client();
               int get_Client_socket_state() { return client_internet_socket; }

    private:
               int initialization();
               int connection(int internet_socket);
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
//cleanup
               int shutdown_return;
    };
}
#endif














