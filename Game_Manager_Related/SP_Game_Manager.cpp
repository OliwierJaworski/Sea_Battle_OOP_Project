#include "SP_Game_Manager.h"
SP_Game_Manager::SP_Game_Manager(int player_type1,int player_type2)
{
    chosen_player_init(player_type1);
    chosen_player_init(player_type2);
}
void SP_Game_Manager::chosen_player_init(int player_Typechosen)
{
    Game_Player * player = nullptr;
    Simple_Ai * Easy_Ai = nullptr;
    AI_Player::First_AI * Harder_Ai = nullptr;
    switch (player_Typechosen)
    {
        case player_types::real_player:
            player = new Game_Player;
            Player_Add_ToGame(* player,false);
            break;
        case player_types::Easy_Ai:
            Easy_Ai = new Simple_Ai;
            Player_Add_ToGame(* Easy_Ai,false);
            break;
        case player_types::Harder_Ai:
            Harder_Ai = new AI_Player::First_AI;
            Player_Add_ToGame(* Harder_Ai,false);
            break;
    }
}
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
            if (player_vector.size()<2)
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
        if(player_vector.at(0)!=  previous_player)
        {
            play_turn();
            previous_player =player_vector.at(0);
        }
        else if(player_vector.at(1) != previous_player)
        {
            play_turn();
            previous_player =player_vector.at(1);
        }
    }
}
void SP_Game_Manager::play_turn()
{
    int curr_state=0;
    switch (curr_state)
    {

    }
}

bool SP_Game_Manager::Game_State_active()
{
    for (auto player:player_vector)
    {
        if(player->Get_Player_boats_alive())
        {
            return true;
        }
        else
            return false;
    }
}

Coordinates SP_Game_Manager::tranlate_to_cords(std::string input_string)
{
    Coordinates User_Cords;
    std::string::size_type pos =input_string.find('.');
    User_Cords.y = input_string.at(pos +1)-'0';
    User_Cords.x = input_string.at(pos -1)-'0';
    return  User_Cords;
}

