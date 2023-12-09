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
    try
    {
        std::string Connection_type = "";
        do
        {
            Connection_type = Player_Input_init();
        }while (Connection_type != "Host" && Connection_type != "Client");
        if (Connection_type == "Host" || Connection_type == "host")
        {
            return TCP_HOST;
        }
        else if (Connection_type == "Client" || Connection_type == "client")
        {
            return Connection_type::TCP_CLIENT;
        }
        else
        throw (Connection_type);
    }
    catch (int connection_error)
    {
        std::cout<< "Wrong int value has been provided bz Player_Input_init";
    }
}

void MP_Game_Manager::Play_Game()
{
    try
    {
        if (Client != nullptr)
        {
            client_play_turn();
        }
        else if (host != nullptr)
        {
            host_play_turn();
        }
        else
           throw("could not find the correct game to bind to" );
    }
    catch (const char * recvderr)
    {
        std::cout<< recvderr;
    }
}
MSG_STRUCT MP_Game_Manager::Player_turn_decision(MSG_STRUCT recvd_content)
{
    MSG_STRUCT Structured_msg;
        if (!Player_Me.Get_Player_boats_alive())
        {
            Structured_msg.MSG_Type = MSG_TYPE::Game_Over;
            Structured_msg.bool_recvd = true;
            return Structured_msg;
        }
        else
        {
            switch (recvd_content.MSG_Type)
            {
                case MSG_TYPE::Init_Message:
                case MSG_TYPE::Directd_Message://dm naar oponent
                    Structured_msg.MSG_Type = MSG_TYPE::Your_Turn;
                    Structured_msg.bool_recvd = true;
                    break;
                case MSG_TYPE::Tile_Info://de attacking player adjust his tile info
                    Player_Me.adj_myEnemymap_ToResponse(recvd_content.y, recvd_content.x, recvd_content.bool_recvd);
                    if(recvd_content.bool_recvd== false)
                    {
                        Structured_msg.MSG_Type = MSG_TYPE::Your_Turn;
                        Structured_msg.bool_recvd = true;
                        break;
                    }
                    else
                    {
                        recvd_content.MSG_Type = MSG_TYPE::Your_Turn;
                        std::cout << recvd_content.MSG_Type <<std::endl;
                    }
                case MSG_TYPE::Your_Turn://voer attack uit
                    Coordinates Player_cords;
                    Player_cords = Player_Me.Attack_Enemy(Player_Me.Player_Input());

                    Structured_msg.MSG_Type = MSG_TYPE::Attack_received;
                    Structured_msg.x = Player_cords.x;
                    Structured_msg.y = Player_cords.y;
                    break;

                case MSG_TYPE::Attack_received://als de opponent u attacked bekijk u map en send die terug als TI
                    Structured_msg.bool_recvd = Player_Me.adj_MyMAP_TOResponse(recvd_content.y, recvd_content.x);

                    Structured_msg.MSG_Type = MSG_TYPE::Tile_Info;
                    Structured_msg.x = recvd_content.x;
                    Structured_msg.y = recvd_content.y;
                    break;

                default:
                    Structured_msg.MSG_Type = MSG_TYPE::Your_Turn;
                    Structured_msg.bool_recvd = true;
                    Structured_msg.message="default case in was called in the switch statement !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
                    break;
            }
        }
    return Structured_msg;
}
void MP_Game_Manager::host_play_turn()
{
    while(keepgamerolling)
    {
        MSG_STRUCT currentmsg = host->deserialize_ToMSG(host->recv(host->get_Client_socket_state()));
        if(currentmsg.MSG_Type==MSG_TYPE::Game_Over)
        {
            keepgamerolling =false ;
        }
        else
        {
            Player_Me.print_map();
            host->send(host->get_Client_socket_state(),host->serialize_Tostring(Player_turn_decision(currentmsg)));
            Player_Me.print_map();
        }
    }
std::cout << "game over!";
}
void MP_Game_Manager::client_play_turn()
{
    while(keepgamerolling)
    {
        MSG_STRUCT currentmsg=Client->deserialize_ToMSG(Client->recv(Client->get_socket_state()));
        if(currentmsg.MSG_Type==MSG_TYPE::Game_Over)
        {
            keepgamerolling =false;
        }
        else
        {
            Player_Me.print_map();
            Client->send(Client->get_socket_state(), Client->serialize_Tostring(Player_turn_decision(currentmsg)));
            Player_Me.print_map();
        }
    }
    std::cout << "game over!";
}

