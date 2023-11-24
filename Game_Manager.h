#ifndef REMADE_SEA_BATTLE_GAME_MANAGER_H
#define REMADE_SEA_BATTLE_GAME_MANAGER_H

#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <thread>
#include <vector>

#include "Game_Player.h"
#include "Tcp_Server_Socket.h"
#include "Tcp_Client_Socket.h"


class Game_Manager
{

public:
//constructor | destructor
    Game_Manager();
    ~Game_Manager();
//public
    int Game_Loop();
    void Game_Loop_Turn_handler(int * playersturn);//PlayTurns
    void set_Game_Type(int type)                                             {Game_Type=type;}
    void Online_Ask_Game_Type();
private:
//private
//Player Core structure
    int Game_Type;
    SBN::Tcp_Server_Socket * Server;
    SBN::Tcp_Client_Socket * Client;
    std::vector<Game_Player *> PlayerVector;
//flexible function datatypes
    int flexible_map_type[10][10];
//extra added functionality
    enum Game_Types{Singleplayer,Multiplayer_host,client};
    enum change_received_data_to{Player_Array,Player_Cords};
    bool Online_waiting_on_connection();
    void Extra_Dots_Loading_Screen(SBN::Tcp_Server_Socket& server);
    bool Online_Start_Correct_Protocol();

//experimental
    void Online_Send_Client_Map();
//initialization & destruction
    void Init_Players();
    void Free_Alloc();
};


#endif
