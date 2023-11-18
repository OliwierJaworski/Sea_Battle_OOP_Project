#include "Game_TCP_Communication.h"
void Game_TCP_Communication::recv_data()
{
    valread = read(new_socket, buffer, 1024 - 1);
}
void Game_TCP_Communication::send_data()
{
    send(new_socket, message.c_str(), 5, 0);
}
Game_TCP_Communication::~Game_TCP_Communication()
{

}