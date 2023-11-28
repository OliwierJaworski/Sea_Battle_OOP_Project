#include "Online_Game_Manager.h"

//constructor | destructor
Online_Game_Manager::Online_Game_Manager()
{
    Init_Players();
}
Online_Game_Manager::~Online_Game_Manager()
{

}
//public
bool Online_Game_Manager::Is_Game_Finished()
{

}

int Online_Game_Manager::Play_Game()
{

}
void Online_Game_Manager::PlayTurns()
{

}

//private
void Online_Game_Manager::Init_Players()
{
    std::unique_ptr<Game_Player> player2 =std::make_unique<Game_Player>();
    std::unique_ptr<Game_Player> player1 =std::make_unique<Game_Player>();

    PlayerVector.push_back(std::move(player1));
    PlayerVector.push_back(std::move(player2));

    std::unique_ptr<Game_Player> player_client =std::make_unique<Game_Player>();
    PlayerVector.push_back(std::move(player_client));
}