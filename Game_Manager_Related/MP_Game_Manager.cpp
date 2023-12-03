#include "MP_Game_Manager.h"
MP_Game_Manager::MP_Game_Manager()
{
   Init_TCP_Connection(filter_input());
}
void MP_Game_Manager::Init_TCP_Connection(int connection_type)
{
    switch (connection_type)
    {
        case TCP_HOST:
            host = std::make_unique<SBN::Tcp_Server_Socket>();
            break;
        case TCP_CLIENT:
            Client =  std::make_unique<SBN::Tcp_Client_Socket>();
            break;
        default:
            std::cout <<"no valid connection type" <<std::endl;
    }
}
std::string MP_Game_Manager::Player_Input_init()
{
    std::string input_read;
    std::cout << "Host or Client?"<< std::endl;
    do
    {
        input_read="";
        std::cin >> input_read;
    }
    while(input_read !="Host" && input_read !="Client");

    return input_read;
}
int MP_Game_Manager::filter_input()
{
    std::string Connection_type="";
    do
    {
        Connection_type = Player_Input_init();
    } while (Connection_type!= "Host" && Connection_type!="Client");
    if (Connection_type=="Host")
    {
        return TCP_HOST;
    }
    else if(Connection_type=="Client")
    {
        return TCP_CLIENT;
    }
    else
       std::cerr <<"wrong connection type";
}

int MP_Game_Manager::Play_Game()
{
        if(Client != nullptr)
        {
            client_play_turn();
        }
        else if(host != nullptr)
        {
            host_play_turn();
        }
        else
            std::cerr<<"could not find the correct game to bind to"<<std::endl;
}
void MP_Game_Manager::host_play_turn()
{
    //while(Game_State_active())
    //{
        Coordinates cords;
        cords= Convert_Message<Coordinates>("AT,1.0",AT);

        std::cout << "cord .y:" << cords.y << " cord .x:" << cords.x << std::endl;
        std::cout << Convert_Message<std::string>("AT,1.0",AT) << std::endl;
    //}
}
void MP_Game_Manager::client_play_turn()
{
    while(Game_State_active())
    {

    }
}
int MP_Game_Manager::Check_message_type(std::string message_received)
{
 if(message_received[2]!=',')//bv "CT,hello from this pc\n"
 {
     std::cerr << "wrong prefix-sign  has been used by the sender";
 }
    message_received.substr(2,std::string::npos);
    int Argument_Amount = 1; //2 but 1 bec 0 counts aswell
    for (int messagetype= 0; messagetype <= Argument_Amount; ++messagetype)
    {
        switch (messagetype)
        {
            case DC:
                if(message_received=="DC")
                {
                    return DC;
                }
            case YT:
                if(message_received=="YT")
                {
                    return YT;
                }
                break;
            default:
                std::cerr << " wrong prefix-data has been used by sender"<<std::endl;
        }
    }
}

template<typename MSG_TYPE>
typename std::conditional<std::is_same<MSG_TYPE, std::string>::value, std::string ,Coordinates>::type MP_Game_Manager::Convert_Message(std::string recvd_message,int msg_type)
{
    switch (msg_type)
    {
        case DC:
            if constexpr (std::is_same<MSG_TYPE,std::string>::value)
            {
                return recvd_message;
            }
            break;
        case AT:
            if constexpr (std::is_same<MSG_TYPE,Coordinates>::value)
            {
                Coordinates cords;
                cords.y=recvd_message.at(3)-'0';//A(0)T(1),(2)3(3).(4)5(5)
                cords.x=recvd_message.at(5)-'0';
                return cords;
            }
            break;
    }
}
bool MP_Game_Manager::Game_State_active()
{

}