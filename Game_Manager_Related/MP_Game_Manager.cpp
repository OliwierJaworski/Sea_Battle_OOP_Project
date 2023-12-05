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
Coordinates MP_Game_Manager::Player_turn_decision()
{

}
void MP_Game_Manager::host_play_turn()
{
 Player_Me.Att_tile_state(Player_Me.Attack_Enemy(tranlate_to_cords(Player_Input())),true);

}
void MP_Game_Manager::client_play_turn()
{

}
Coordinates MP_Game_Manager::tranlate_to_cords(std::string input_string)
{
    Coordinates User_Cords;
    std::string::size_type pos =input_string.find('.');
    User_Cords.y = input_string.at(pos +1)-'0';
    User_Cords.x = input_string.at(pos -1)-'0';
    return  User_Cords;
}
std::string MP_Game_Manager::Player_Input()
{
    std::string input_read;
    std::cout << "type x.y to attack"<< std::endl;

    do
    {
        input_read="";
        std::cin >> input_read;
    }
    while(input_read.size()<3);

    return input_read;
}

bool MP_Game_Manager::Game_State_active()
{

}