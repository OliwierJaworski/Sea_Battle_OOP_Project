#include "SP_Game_Manager.h"
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
          play_turn(Player_Me,Player_Enemy);
          previous_player =&Player_Me;
      }
      else if(& Player_Enemy != previous_player)
      {
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

}
std::string SP_Game_Manager::Player_Input()
{
    std::string input_read;
    std::cout << "type At,x.y to attack or Ct,'your text' to chat with your opponent"<< std::endl;
    do
    {
        std::cout << "You need to specify the type" <<std::endl;
        std::cin >> input_read;
    }
    while(!Correct_Input_type(input_read));
    return input_read;
}
bool SP_Game_Manager::Correct_Input_type(std::string user_input)
{

    std::string::size_type pos = user_input.find(',');//size_type to guarantee it doesnt overflow
    if (pos != std::string::npos)
    {
         user_input.substr(pos, std::string::npos);
    }
    if (user_input == "At" || user_input == "Ct")
    {
        return true;
    }
    else false;
}
Coordinates SP_Game_Manager::tranlate_to_cords(std::string input_string)
{
    Coordinates User_Cords;
    std::string::size_type pos = input_string.find(',');//size_type to guarantee it doesnt overflow
    if (pos != std::string::npos)
    {
        input_string.substr(0, pos);
    }
    pos =input_string.find('.');
    User_Cords.y = input_string.at(pos -1);
    User_Cords.x = input_string.at(pos +1);
    return  User_Cords;
}

