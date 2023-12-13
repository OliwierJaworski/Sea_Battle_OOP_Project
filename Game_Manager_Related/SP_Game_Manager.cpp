#include "SP_Game_Manager.h"
bool SP_Game_Manager::Player_Add_ToGame(Game_Player & curr_player,bool identical_players_allowed)
{
        if (!identical_players_allowed)
        {
            try
            {
            bool unique_id = true;
            for (auto playercurr_vector: player_vector)
            {
                if (curr_player.get_player_id() == playercurr_vector->get_player_id())
                {
                    unique_id = false;
                }
            }
            if (unique_id)
            {
                player_vector.push_back(curr_player.get_player_id());
                std::cout << "player has been added succesfully to the player pool" << std::endl;
                return true;
            }
            else
            {
               throw::std::runtime_error("cant have 2 indentical players when using the unique player wrapper");
            }
            }
            catch(const std::exception& e)
            {
             std::cerr << e.what() << std::endl;
            }
        }
        else
        {
            try
            {
            if (player_vector.size()>2)
            {
                player_vector.push_back(curr_player.get_player_id());
                return true;
            }
            else
            {
                throw std::runtime_error("cant have more than 2 player instances in a game!");
            }
            }
            catch (const std::exception& e)
            {
                std::cerr<< e.what() <<std::endl;
            }
        }
    return false;
}
bool SP_Game_Manager::Play_Game()
{
    Game_Player * previous_player= nullptr;
    while(Game_State_active())
    {
        if(& Player_Me!= previous_player)
        {

        }
        else if(& Player_Enemy != previous_player)
        {

        }
    }
    return true;
}

bool SP_Game_Manager::Game_State_active()
{
    if (Player_Me.Get_Player_boats_alive() && Player_Enemy.Get_Player_boats_alive())
    {
        return true;
    }
    return false;
}

Coordinates SP_Game_Manager::tranlate_to_cords(std::string input_string)
{
    Coordinates User_Cords;
    std::string::size_type pos =input_string.find('.');
    User_Cords.y = input_string.at(pos +1)-'0';
    User_Cords.x = input_string.at(pos -1)-'0';
    return  User_Cords;
}

