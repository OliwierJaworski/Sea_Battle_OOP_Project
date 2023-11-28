#include "Game_Manager_Loader.h"
Game_Manager_Loader::Game_Manager_Loader()
{
    Game_Type(Player_Option());
}
void Game_Manager_Loader::Game_Type(std::string User_Option)
{
    if (User_Option=="Singleplayer")
    {
        SP_game = std::make_unique<Game_Manager>();
    }
    else
    {
        ONL_game =std::make_unique<Online_Game_Manager>();
    }
}
std::string Game_Manager_Loader::Player_Option()
{
    std::string Player_Choice;
    std::cout << "Singleplayer or Multiplayer";
    do
    {
        std::cin >> Player_Choice;
    }
    while(Player_Choice != "Singleplayer" && Player_Choice != "Multiplayer");
    return Player_Choice;
}