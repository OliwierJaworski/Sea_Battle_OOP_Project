#include "Tcp_Client_Socket.h"
//constructor | destructor
    Tcp_Client_Socket::Tcp_Client_Socket()
    {
        Create_Socket();
        Bind_to_port();
        Client_Setup_Input();
    }

//public | private
//TCP_Client Core structure
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
    bool Tcp_Client_Socket::Bind_to_port()
    {
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(this->Used_Port);
        return true;
    }
    bool Tcp_Client_Socket::Connect_to_Server()
    {
        if (inet_pton(AF_INET, ipAddress, &serv_addr.sin_addr)<= 0)
        {
            printf("\nInvalid address/ Address not supported \n");
            return -1;
        }

        if ((status= connect(new_socket, (struct sockaddr*)&serv_addr,sizeof(serv_addr)))
            < 0) {
            printf("\nConnection Failed \n");
            return -1;
        }
        send_data("I WANT TO CONNECT");
        return true;
    }
    void Tcp_Client_Socket::Client_Setup_Input()
    {
/*
        std::string New_IP;

        std::cout << "what ip you want to connect to " << std::endl;
        std::cin >> New_IP;

        set_IP(New_IP);
*/
        Connect_to_Server();
    }

//extra added functionality

//initialization & destruction
    bool Tcp_Client_Socket::close_socket()
    {
        close(new_socket);

        return true;
    }