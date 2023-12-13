#include "Game_Manager_Loader.h"


std::string Game_Manager_Loader::Player_Option()
    {
    std::string UserGame;
    std::cout<< "Multiplayer Or Singleplayer? :>";
        UserGame="singleplayer";
        return UserGame;
   do
   {
       std::cin >> UserGame;
   }   while (UserGame !="singleplayer" && UserGame != "multiplayer");
    }
void Game_Manager_Loader::Game_Type(std::string User_Option)
{
   if(User_Option =="singleplayer")
   {
       std::cout << "0 for real player, 1 for easy ai, 2 for harder ai" << std::endl;
       int player_type =-1;
       //do
       //{
       //    std::cin >> player_type;
       //}
       //while(player_type<0 || player_type>2);
       player_type=1;
      SP_Game = std::make_unique<SP_Game_Manager>(0,player_type);
      forward_SP_playgame();
   }
   if(User_Option =="multiplayer")
   {
       MP_Game = std::make_unique<MP_Game_Manager>();
       forward_MP_playgame();
   }
}
void Game_Manager_Loader::forward_SP_playgame()
{
    SP_Game->Play_Game();
}
void Game_Manager_Loader::forward_MP_playgame()
{
    MP_Game->Play_Game();
}


