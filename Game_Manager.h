#ifndef REMADE_SEA_BATTLE_GAME_MANAGER_H
#define REMADE_SEA_BATTLE_GAME_MANAGER_H

#include <vector>
#include <string>
#include <iostream>


#include "Game_Player.h"
#include "Tcp_Client_Socket.h"
#include "Tcp_Server_Socket.h"

//////////////////////////////////////////////////////////////////////////////
class Game_Manager
{
public:
    Game_Manager();
    virtual ~Game_Manager()=0;

    virtual int Play_Game()=0;

private:
    enum Game_Type{Singleplayer,Multiplayer_Host,Multiplayer_Client};
    std::vector<std::unique_ptr<Game_Player>> PlayerVector;
    virtual void Init_Players()=0;
    virtual bool Is_Game_Finished()=0;
};
//////////////////////////////////////////////////////////////////////////////
class SP_Game_Manager : Game_Manager
{
public:
    SP_Game_Manager() ;
    ~SP_Game_Manager() override ;

    int Play_Game() override;
    void PlayTurns(int * playersturn);

private:
    std::vector<std::unique_ptr<Game_Player>> PlayerVector;
    void Init_Players() override;
    bool Is_Game_Finished() override;
};
//////////////////////////////////////////////////////////////////////////////
class Client_Game_Manager : Game_Manager
{
public:
    Client_Game_Manager() ;
    ~Client_Game_Manager() override;

    int Play_Game() override;
    void PlayTurns();

private:
    std::vector<std::unique_ptr<Game_Player>> PlayerVector;
    SBN::Tcp_Client_Socket Client_Connection;
    void Init_Players() override;
    bool Is_Game_Finished() override;
};
//////////////////////////////////////////////////////////////////////////////
class Host_Game_Manager : Game_Manager
{
public:
    Host_Game_Manager() ;
    ~Host_Game_Manager() override;

    int Play_Game() override;
    void PlayTurns();

private:
    std::vector<std::unique_ptr<Game_Player>> PlayerVector;
    SBN::Tcp_Server_Socket Server_Connection;
    void Init_Players() override;
    bool Is_Game_Finished() override;
};
#endif
