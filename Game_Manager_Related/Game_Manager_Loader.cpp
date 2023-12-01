#include "Game_Manager_Loader.h"


Game_Manager_Loader::Game_Manager_Loader()
{
    Game_Type(Player_Option());
}

    std::string Game_Manager_Loader::Player_Option()
    {
    std::string UserGame ="singleplayer";
    std::cout<< "Multiplayer Or Singleplayer? :>";
    do
    {
        //std::cin >> UserGame;
    } while (UserGame !="singleplayer" && UserGame != "multiplayer");
        return UserGame;
    }

void Game_Manager_Loader::Game_Type(std::string User_Option)
{
   if(User_Option =="singleplayer")
   {
      SP_Game = std::make_unique<SP_Game_Manager>();
   }
    if(User_Option =="multiplayer")
   {
       MP_Game = std::make_unique<MP_Game_Manager>();
   }
}


