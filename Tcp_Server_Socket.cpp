#include "Tcp_Server_Socket.h"

Tcp_Server_Socket::Tcp_Server_Socket()
{
   Create_Socket();
   Bind_to_port();
   listen_for_connections();
}

int  Tcp_Server_Socket::Create_Socket()
{
    if ((server_client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        std::cerr << "socket failed" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    std::cout <<"created socket!"<< std::endl;
    return server_client_fd;
}

bool Tcp_Server_Socket::Bind_to_port()
{
    address.sin_family = AF_INET;
    address.sin_port = htons(Used_Port);

    address.sin_addr.s_addr = INADDR_ANY;

    if (setsockopt(server_client_fd, SOL_SOCKET,SO_REUSEADDR | SO_REUSEPORT, &opt,sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    if (bind(server_client_fd, (struct sockaddr*)&address,
             sizeof(address))
        < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    std::cout <<"binded to port!"<< std::endl;
    return true;
}
bool Tcp_Server_Socket::listen_for_connections()
{
    if (listen(server_client_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket= accept(server_client_fd, (struct sockaddr*)&address,&addrlen))< 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    valread = read(new_socket, buffer,1024 - 1);

    return true;
}



bool Tcp_Server_Socket::close_socket()
{

    close(new_socket);
    close(server_client_fd);

    std::cout <<"closed socket!"<< std::endl;
    return true;
}



