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
MSG_STRUCT MP_Game_Manager::Player_turn_decision(MSG_STRUCT recvd_content)
{
    MSG_STRUCT Structured_msg;
    switch (recvd_content.MSG_Type) 
    {
        case MSG_TYPE::DM:
            Structured_msg.MSG_Type=MSG_TYPE::YT;
            break;
        case MSG_TYPE::AT:
            Structured_msg.bool_recvd =Player_Me.Verify_Ifenemy_Hit(recvd_content.y,recvd_content.x);
            Structured_msg.MSG_Type=MSG_TYPE::TI;
            break;
        case MSG_TYPE::TI:
            Player_Me.adj_map_ToResponse(recvd_content.y,recvd_content.x,recvd_content.bool_recvd);
            Structured_msg.MSG_Type=MSG_TYPE::YT;
            break;
        case MSG_TYPE::YT:
            if(recvd_content.bool_recvd)
            {
                Coordinates Player_cords;
                Player_cords=Player_Me.Attack_Enemy(Player_Me.Player_Input());
                Structured_msg.x=Player_cords.x;
                Structured_msg.y=Player_cords.y;
                Structured_msg.MSG_Type=MSG_TYPE::AT;
            }
            else
                Structured_msg.MSG_Type=MSG_TYPE::YT;
                Structured_msg.bool_recvd=true;
            break;
        default:
            std::cerr << "wrong Type has been specified by the sender"<<std::endl;
            return Structured_msg;
    }
}
void MP_Game_Manager::host_play_turn()
{
    while(1)
    {
        host->send(host->get_Client_socket_state(),host->serialize_Tostring(Player_turn_decision(host->deserialize_ToMSG(host->recv(host->get_Client_socket_state())))));
    }

}
void MP_Game_Manager::client_play_turn()
{
    while(1)
    {
        //Player_turn_decision(Client->deserialize_ToMSG(Client->recv(Client->get_socket_state())));
        Client->send(Client->get_socket_state(),Client->serialize_Tostring(Player_turn_decision(Client->deserialize_ToMSG(Client->recv(Client->get_socket_state())))));
    }

}


bool MP_Game_Manager::Game_State_active()
{

}