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

void Tcp_Server_Socket::Send_Formatted_Data()
{

}
template<typename Extr_msg>
typename std::conditional<std::is_same<Extr_msg, bool>::value, bool ,Coordinates>::type
extract_frm_string(std::string recvd_message,int data_type)
{
    if constexpr (std::is_same<Extr_msg,bool>::value)
    {
        bool bool_recvd;
        switch (data_type)
        {
            case MR:    //valt gewoon door naar de YT case
            case YT:
                recvd_message.substr(0,2);
                if(recvd_message=="TRUE")
                {
                    bool_recvd= true;
                }
                if(recvd_message=="FALSE")
                {
                    bool_recvd= false;
                }
                else
                    std::cerr << "Tcp_Server_Socket::extract_frm_string : could not convert to bool" << std::endl;
                return bool_recvd;
            case TI:
                recvd_message.substr(0,6);//bv :TI,1.1.true
                if(recvd_message=="TRUE")
                {
                    bool_recvd= true;
                }
                if(recvd_message=="FALSE")
                {
                    bool_recvd= false;
                }
                else
                    std::cerr << "Tcp_Server_Socket::extract_frm_string : could not convert to bool" << std::endl;
                return bool_recvd;
        }
    }
    if constexpr (std::is_same<Extr_msg,Coordinates>::value)
    {
        Coordinates cord_pair_recvd;
        cord_pair_recvd.y=recvd_message.at(3)-'0';
        cord_pair_recvd.x=recvd_message.at(5)-'0';
        return cord_pair_recvd;
    }
    else
        std::cerr<<"wrong type was passed to function :extract_frm_string"<<std::endl;
}

Tcp_Server_Socket::TCP_RecvData_Format Tcp_Server_Socket::Format_Recvd_Data(std::string recvd_data)
{
    int data_type =Get_Data_Type(recvd_data);
    recvd_data.substr(0,2);

    Tcp_Server_Socket::TCP_RecvData_Format Formatted_data;
    Formatted_data.MSG_Type =data_type;
    switch (data_type)
    {
        case YT:
            Formatted_data.recvd_bool =extract_frm_string<bool>(recvd_data,YT);
            return Formatted_data;
            break;
        case AT:
            Formatted_data.var_cords=extract_frm_string<Coordinates>(recvd_data,AT);
            return Formatted_data;
            break;
        case TI:
            Formatted_data.var_cords=extract_frm_string<Coordinates>(recvd_data,TI);
            break;
        case DM:
            Formatted_data.var_string=recvd_data;
            return Formatted_data;
            break;
        case MR:
            Formatted_data.recvd_bool= extract_frm_string<bool>(recvd_data,MR);
            return Formatted_data;
            break;
    }
}

int Tcp_Server_Socket::Get_Data_Type(std::string recvd_data)
{
    recvd_data.substr(2,std::string::npos);
    if (recvd_data=="YT")
    {
        return YT;
    }
    else if(recvd_data=="AT")
    {
        return AT;
    }
    else if(recvd_data=="TI")
    {
        return TI;
    }
    else if(recvd_data=="DM")
    {
        return DM;
    }
    else if(recvd_data=="MR")
    {
        return MR;
    }
    else
        std::cerr<<"received unsupported data prefix";
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



