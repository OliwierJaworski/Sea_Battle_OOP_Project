#include "Game_TCP_Communication.h"
//constructor | destructor
Game_TCP_Communication::~Game_TCP_Communication()
{

}

//public | private
//Tcp_Communication Core structure
void Game_TCP_Communication::recv_data()
{
    valread = read(new_socket, buffer, 1024 - 1);
}
void Game_TCP_Communication::send_data(std::string inputmessage)
{
    send(new_socket, inputmessage.c_str(), inputmessage.size(), 0);
}
//extra added functionality

//initialization & destruction