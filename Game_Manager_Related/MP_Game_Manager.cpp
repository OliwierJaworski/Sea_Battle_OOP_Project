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
std::string MP_Game_Manager::Player_turn_decision()
{
   std::string complete_string_winfo;
   std::string user_input;
   int message_prefix;

   std::cout << "would you like to attack 'AT' or send a message to your oponent 'DM' " << std::endl;
   do
   {
    std::cin >> user_input;
    message_prefix =Check_message_type(user_input);
   }while(message_prefix!=DM && message_prefix!=AT);

    if(message_prefix==DM)
    {
        complete_string_winfo.append("DM,");
        std::string msg_content;

        std::cout<< "what would you like to say?" <<std::endl;
        //std::getline(std::cin, msg_content);
        std::cin >> msg_content;

        complete_string_winfo.append(msg_content);
        host->send(host->get_Client_socket_state(),complete_string_winfo);
    }
    else if(message_prefix==AT)
    {
        complete_string_winfo.append("AT,");
        std::string input_read;
        std::cout << "type x.y to attack"<< std::endl;
        do
        {
            input_read="";
            std::cin >> input_read;
        }
        while(input_read.size()<3);
        complete_string_winfo.append(input_read);
        host->send(host->get_Client_socket_state(),complete_string_winfo);
    }
    else
        std::cerr << "player_turn_decision:: this part has not been implemented yet"<<std::endl;
}
void MP_Game_Manager::host_play_turn()
{
    while(Game_State_active())
    {
        if (host->get_Client_socket_state()>0)//check if client is still connected
        {
           Player_Me.print_map(0);
           Player_Me.print_map(1);
           Player_turn_decision();
        }
    }
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
     //std::cerr << "wrong prefix-sign  has been used by the sender";
 }
    message_received.substr(2,std::string::npos);
    int ARG_Am = 2;

    for (int messagetype= 0; messagetype <= ARG_Am; ++messagetype)
    {
        switch (messagetype)
        {
            case DM:
                if(message_received=="DM")
                {
                    return DM;
                }
            case YT:
                if(message_received=="YT")
                {
                    return YT;
                }
                break;
            case AT:
                if(message_received=="AT")
                {
                    return AT;
                }
                break;
        }
    }
}

template<typename MSG_TYPE>
typename std::conditional<std::is_same<MSG_TYPE, std::string>::value, std::string ,Coordinates>::type MP_Game_Manager::Convert_Message(std::string recvd_message,int msg_type)
{
    switch (msg_type)
    {
        case DM:
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