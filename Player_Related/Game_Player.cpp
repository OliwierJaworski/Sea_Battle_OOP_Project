#include "Game_Player.h"

Coordinates Game_Player::Attack_Enemy(Coordinates User_Input_Cords)
    {
        Coordinates Attack_Enemy_Cords = User_Input_Cords;
        int x= Attack_Enemy_Cords.x;
        int y= Attack_Enemy_Cords.y;
        std::cout << "Game_Player cords x:" << x << " y:" << y << std::endl;
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

    bool  Game_Player::Get_Player_boats_alive()
    {
        return Get_map_instance().any_ship_alive();
    }

    void Game_Player::print_map()
    {
        Get_map_instance().print_map();
    }


