#include "Game_Player.h"
    Coordinates Game_Player::Attack_Enemy()
    {
     Coordinates user_cord= tranlate_to_cords(Player_Input());
        return user_cord;
    }
    Coordinates Game_Player::tranlate_to_cords(std::string input_string)
    {
        Coordinates User_Cords;
        std::string::size_type pos =input_string.find('.');
        User_Cords.y = input_string.at(pos +1)-'0';
        User_Cords.x = input_string.at(pos -1)-'0';
        return  User_Cords;
    }
    std::string Game_Player::Player_Input()
    {
        std::string output_format;
        std::string cord ="";
        do
        {
            std::cout << "x coordinate(number):" << std::endl;
            std::cin >> cord;
        }while(cord.size()!=1  || cord > "9" || cord < "0");
        output_format+=cord+'.';
        cord ="";
        do
        {
            std::cout << "y coordinate(number):" << std::endl;
            std::cin >> cord;
        }while(cord.size()!=1 || cord > "9" || cord < "0");
        output_format+=cord;
        return output_format;
    }

    const bool  Game_Player::Get_Player_boats_alive()
    {
        return Get_map_instance().any_ship_alive();
    }

    const void Game_Player::print_map()
    {
        Get_map_instance().print_map();
    }


