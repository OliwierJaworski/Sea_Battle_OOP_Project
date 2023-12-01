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
std::string MP_Game_Manager::Player_Input()
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
        Connection_type = Player_Input();
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
bool MP_Game_Manager::Play_Game()
{

}
void MP_Game_Manager::play_turn(Game_Player & Current_Player,Game_Player & Enemy_Player)
{

}
bool MP_Game_Manager::Game_State_active()
{

}