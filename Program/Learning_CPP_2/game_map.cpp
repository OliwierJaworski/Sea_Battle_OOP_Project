#include "game_map.h"
#include "boats.h"
#include <time.h>
#include <iostream>



void Game_Map::init_matrix()
{
    for (int x = 0; x < 10; ++x)
    {
        for (int y = 0; y < 10; ++y)
        {
            game_matrix[x][y]= 0;
        }
    }
}

void Game_Map::init_boats()
{
    Carrier* Carrier1 = new Carrier(5, "Carrier");
    BoatVector.push_back(Carrier1);

    Battleship* Battleship1 = new Battleship(4, "Battleship");
    BoatVector.push_back(Battleship1);

    Cruiser* Cruiser1 = new Cruiser(3, "Cruiser");
    BoatVector.push_back(Cruiser1);

    Submarine* Submarine1 = new Submarine(3, "Submarine");
    BoatVector.push_back(Submarine1);

    Destroyer* Destroyer1 = new Destroyer(2, "Destroyer");
    BoatVector.push_back(Destroyer1);
}

void Game_Map::clear_boats_data()
{
    BoatVector.clear();
}

std::string Game_Map::player_input_tile(int current_boat)
{
    std::string x_loc;
    std::string y_loc;
    std::cout << "where would you like to place the " << BoatVector[current_boat]->boatname << " on the x axis of size " <<BoatVector[current_boat]->boatsize << std::endl;
    std::cin >> x_loc;
    std::cout << "where would you like to place the " << BoatVector[current_boat]->boatname << " on the y axis  of size " <<BoatVector[current_boat]->boatsize << std::endl;
    std::cin >> y_loc;

    std::string place_loc =x_loc + "," + y_loc;
    return place_loc;
}

std::string Game_Map::player_input_direction(int current_boat)
{
    std::string direction;
    std::cout << "in which direction would you like to place the " << BoatVector[current_boat]->boatname << " of size " <<BoatVector[current_boat]->boatsize << std::endl;
    std::cout << "you can choose: right, left, up, down." << std::endl;
    std::cin >> direction;

    return direction;
}

int Game_Map::verify_boat_placement(std::string loc, std::string rot, int currentboat_size)
{
    int free;
    int x_loc;
    int y_loc;

    size_t seperatorPos = loc.find(',');

    if(seperatorPos !=std::string::npos)
    {
        x_loc = std::stoi(loc.substr(0, seperatorPos));
        y_loc = std::stoi(loc.substr(seperatorPos + 1));
    }

    for (int var = 0; var < currentboat_size -1; ++var)
    {

        if(rot == "right")
        {
            if(x_loc + currentboat_size > 10)
            {
             std::cout << "The ship doesn't fit in the 'right' direction at (" << x_loc << ", " << y_loc << ")." << std::endl;
            }
            else if(game_matrix[x_loc +var][y_loc] ==0)
            {
             free=1;
            }
            else
            {
             return 0;
            }
        }
        if(rot == "left")
        {
            if(x_loc - currentboat_size > 10)
            {
                std::cout << "The ship doesn't fit in the 'right' direction at (" << x_loc << ", " << y_loc << ")." << std::endl;
            }
            else if(game_matrix[x_loc -var][y_loc] ==0)
            {
                free=1;
            }
            else
            {
                return 0;
            }
        }
        if(rot == "up")
        {
            if(y_loc - currentboat_size > 10)
            {
                std::cout << "The ship doesn't fit in the 'right' direction at (" << x_loc << ", " << y_loc << ")." << std::endl;
            }
            else if(game_matrix[x_loc ][y_loc - var] ==0)
            {
                free=1;
            }
            else
            {
               return 0;
            }
        }
        if(rot == "down")
        {
            if(y_loc + currentboat_size > 10)
            {
                std::cout << "The ship doesn't fit in the 'right' direction at (" << x_loc << ", " << y_loc << ")." << std::endl;
            }
            else if(game_matrix[x_loc ][y_loc + var] ==0)
            {
                free=1;
            }
            else
            {
                return 0;
            }
        }
    }
    return 1;
}

void Game_Map::place_boats(std::string loc, std::string rot,int Can_place, int currentboat_size)
{
    int x_loc;
    int y_loc;

    size_t seperatorPos = loc.find(',');

    if(seperatorPos !=std::string::npos)
    {
        x_loc = std::stoi(loc.substr(0, seperatorPos));
        y_loc = std::stoi(loc.substr(seperatorPos + 1));
    }

    if(rot == "right")
    {
        for (int var = 0; var < currentboat_size -1; ++var)
        {
            game_matrix[x_loc+ var][y_loc]=1;

        }
    }
    if(rot == "left")
    {
        for (int var = 0; var < currentboat_size -1; ++var)
        {
            game_matrix[x_loc- var][y_loc]=1;

        }
    }
    if(rot == "up")
    {
        for (int var = 0; var < currentboat_size -1; ++var)
        {
            game_matrix[x_loc][y_loc- var]=1;

        }
    }
    if(rot == "down")
    {
        for (int var = 0; var < currentboat_size -1; ++var)
        {
            game_matrix[x_loc][y_loc+ var]=1;

        }
    }
}
