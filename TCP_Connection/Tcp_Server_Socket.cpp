#include "Tcp_Server_Socket.h"

using namespace SBN;
Tcp_Server_Socket::Tcp_Server_Socket()
{
   bind_to_client();
}
Tcp_Server_Socket::~Tcp_Server_Socket()
{
    cleanup(internet_socket, client_internet_socket);
#ifdef _WIN32
    OSCleanup();
#endif
}
void Tcp_Server_Socket::bind_to_client()
{
#ifdef _WIN32
    OSInit();
#endif
    std::cout << " the tcp socket is initializing.." <<std::endl;
    internet_socket = initialization();
    client_internet_socket = connection(internet_socket);
    recv(client_internet_socket);
}

int Tcp_Server_Socket::initialization()
{
    memset(&internet_address_setup, 0, sizeof internet_address_setup);
    internet_address_setup.ai_family = AF_UNSPEC;
    internet_address_setup.ai_socktype = SOCK_STREAM;
    internet_address_setup.ai_flags = AI_PASSIVE;
    getaddrinfo_return = getaddrinfo(NULL, "24042", &internet_address_setup, &internet_address_result);
    if (getaddrinfo_return != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(getaddrinfo_return));
        exit(1);
    }

    internet_socket = -1;
    internet_address_result_iterator = internet_address_result;
    while (internet_address_result_iterator != NULL) {
        //Step 1.2
        internet_socket = socket(internet_address_result_iterator->ai_family,
                                 internet_address_result_iterator->ai_socktype,
                                 internet_address_result_iterator->ai_protocol);
        if (internet_socket == -1) {
            perror("socket");
        } else {
            //Step 1.3
            int bind_return = bind(internet_socket, internet_address_result_iterator->ai_addr,
                                   internet_address_result_iterator->ai_addrlen);
            if (bind_return == -1) {
                perror("bind");
                close(internet_socket);
            } else {
                //Step 1.4
                int listen_return = listen(internet_socket, 1);
                if (listen_return == -1) {
                    close(internet_socket);
                    perror("listen");
                } else {
                    break;
                }
            }
        }
        internet_address_result_iterator = internet_address_result_iterator->ai_next;
    }

    freeaddrinfo(internet_address_result);

    if (internet_socket == -1) {
        fprintf(stderr, "socket: no valid socket address found\n");
        exit(2);
    }

    return internet_socket;
}
int Tcp_Server_Socket::connection(int internet_socket)
{
    client_internet_address_length = sizeof client_internet_address;
    client_socket = accept(internet_socket, (struct sockaddr *) &client_internet_address,&client_internet_address_length);
    if (client_socket == -1)
    {
        perror("accept");
        close(internet_socket);
        exit(3);
    }
    return client_socket;
}

void Tcp_Server_Socket::recv(int internet_socket)
{
    int number_of_bytes_received = 0;
    char buffer[1000];
    number_of_bytes_received = ::recv(internet_socket, buffer, (sizeof buffer) - 1, 0);
    if (number_of_bytes_received == -1)
    {
        perror("recv");
    } else {
        buffer[number_of_bytes_received] = '\0';
        printf("Received : %s\n", buffer);
    }

}
void Tcp_Server_Socket::send(int internet_socket,std::string StringData_ToBe_send)
{
    number_of_bytes_send = 0;
    std::cout << StringData_ToBe_send << "send :" << StringData_ToBe_send <<std::endl;
    number_of_bytes_send = ::send(internet_socket, StringData_ToBe_send.c_str(), StringData_ToBe_send.size(), 0);
    if (number_of_bytes_send == -1) {
        perror("send");
    }
}

void Tcp_Server_Socket::cleanup(int internet_socket, int client_internet_socket)
{
#ifdef _WIN32
    shutdown_return = shutdown( internet_socket, SD_RECEIVE );
#else
    shutdown_return = shutdown(client_internet_socket, SHUT_RD);
#endif
    if (shutdown_return == -1)
    {
        perror("shutdown");
    }

    close(client_internet_socket);
    close(internet_socket);
}

