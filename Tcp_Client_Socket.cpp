#include "Tcp_Client_Socket.h"
    Tcp_Client_Socket::Tcp_Client_Socket()
    {
        Create_Socket();
        Bind_to_port();
        //Connect_to_Server();
    }

    int Tcp_Client_Socket::Create_Socket()
    {
        if ((new_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
            std::cerr << "socket failed" << std::endl;
            std::exit(EXIT_FAILURE);
        }
        std::cout <<"created socket!"<< std::endl;
        return new_socket;
    }
    Tcp_Client_Socket::~Tcp_Client_Socket()
    {
        close_socket();
    }
    bool Tcp_Client_Socket::Bind_to_port()
    {
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(Used_Port);
        return true;
    }

    bool Tcp_Client_Socket::Connect_to_Server()
    {

        if (inet_pton(AF_INET,ipAddress, &serv_addr.sin_addr)<= 0)
        {
            printf("\nInvalid address/ Address not supported \n");
            exit(EXIT_FAILURE);
        }
        if ((status = connect(new_socket, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) < 0)
        {

            perror("Connection Failed");
            throw std::runtime_error("Connection Failed");
        }
        return true;
    }
    bool Tcp_Client_Socket::close_socket()
    {
        close(new_socket);

        return true;
    }