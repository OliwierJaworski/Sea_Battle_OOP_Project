#include "SP_Game_Manager.h"
SP_Game_Manager::SP_Game_Manager()
{

}
SP_Game_Manager::~SP_Game_Manager()
{

}
bool SP_Game_Manager::Play_Game()
{
    Game_Player * previous_player= nullptr;
    while(Game_State_active())
    {
      if(& Player_Me!= previous_player)
      {
          std::cout <<"PLAYER Me turn "<<std::endl;
          Player_Me.print_map(0);
          Player_Me.print_map(1);
          play_turn(Player_Me,Player_Enemy);
          previous_player =&Player_Me;
      }
      else if(& Player_Enemy != previous_player)
      {
          std::cout <<"PLAYER Enemy turn "<<std::endl;
          Player_Enemy.print_map(0);
          Player_Enemy.print_map(1);
          play_turn(Player_Enemy,Player_Me);
          previous_player =& Player_Enemy;
      }
    }
}
void SP_Game_Manager::play_turn(Game_Player & Current_Player,Game_Player & Enemy_Player)
{
    Current_Player.Attack_Enemy(Enemy_Player,tranlate_to_cords(Player_Input()));
}
bool SP_Game_Manager::Game_State_active()
{
    if (Player_Me.Get_Player_boats_alive() && Player_Enemy.Get_Player_boats_alive())
    {
        return true;
    }
    return false;
}
std::string SP_Game_Manager::Player_Input()
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

Coordinates SP_Game_Manager::tranlate_to_cords(std::string input_string)
{
    Coordinates User_Cords;
    std::string::size_type pos =input_string.find('.');
    User_Cords.y = input_string.at(pos +1)-'0';
    User_Cords.x = input_string.at(pos -1)-'0';
    return  User_Cords;
}

