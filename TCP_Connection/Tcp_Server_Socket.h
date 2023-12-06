#ifndef REMADE_SEA_BATTLE_TCP_SERVER_SOCKET_H
#define REMADE_SEA_BATTLE_TCP_SERVER_SOCKET_H
#include "TCP_SHARED.h"

namespace SBN//SEA_Battle_Networking
{

    class Tcp_Server_Socket : public TCP_SHARED
    {
    public:
        Tcp_Server_Socket();
        ~Tcp_Server_Socket();
        void bind_to_client();
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














