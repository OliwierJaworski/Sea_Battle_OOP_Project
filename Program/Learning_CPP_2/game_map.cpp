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
    Battleship* Battleship1 = new Battleship(4, "Battleship");
    BoatVector.push_back(Battleship1);

    Destroyer* Destroyer1 = new Destroyer(2, "Destroyer");
    BoatVector.push_back(Destroyer1);

    Carrier* Carrier1 = new Carrier(5, "Carrier");
    BoatVector.push_back(Carrier1);

    Cruiser* Cruiser1 = new Cruiser(3, "Cruiser");
    BoatVector.push_back(Cruiser1);

    Submarine* Submarine1 = new Submarine(3, "Submarine");
    BoatVector.push_back(Submarine1);


}

void Game_Map::clear_boats_data()
{
    BoatVector.clear();
}

int Game_Map::Calc_Boat_Fit(int x, int y, int size, int boat_rot)
{
    int willfit=0;

        switch (boat_rot)
        {
        case 0://to right
            if(x + size <= 9 )
            {
            for (int var = 0; var < size; ++var)//0,1,2,3,4->size 5
            {

                if(game_matrix[y][x+ var]==0)
                {
                    willfit=0;
                }
                else
                {
                    return 1;
                }
            }
            }
            else
            {
                return 1;
            }
        break;

        case 1://to left
        if(x - size >= 0 )
            {
            for (int var = 0; var < size; ++var)//0,1,2,3,4->size 5
            {

                if(game_matrix[y][x - var]==0)
                {
                    willfit=0;
                }
                else
                {
                    return 1;
                }
            }
            }
            else
            {
                return 1;
            }
            break;

        case 2://up
            if(y - size >= 0 )
            {
            for (int var = 0; var < size; ++var)//0,1,2,3,4->size 5
            {
                if(game_matrix[y- var][x]==0)
                {
                    willfit=0;
                }
                else
                {
                   return 1;
                }
            }
            }
            else
            {
                return 1;
            }
            break;
        case 3://down
            if(y + size <= 9 )
            {
            for (int var = 0; var < size; ++var)//0,1,2,3,4->size 5
            {
                if(game_matrix[y+ var][x]==0)
                {
                    willfit=0;
                }
                else
                {
                    return 1;
                }
            }
            }
            else
            {
            return 1;
            }
            break;

        default:
            std::cout<< "wrong rotation variable has been given"<< std::endl;
            break;
        }

    return willfit;
}
void Game_Map::Boat_Map_Placer(int x, int y, int size, int boat_rot)
{
    switch (boat_rot)
    {
    case 0://to right
          std::cout<< "it reaches the case 0"<< std::endl;
        for (int var = 0; var < size; ++var)//0,1,2,3,4->size 5
        {
            game_matrix[y][x + var]+=1;
        }
        break;
    case 1://to left
        std::cout<< "it reaches the case 1"<< std::endl;
        for (int var = 0; var < size; ++var)//0,1,2,3,4->size 5
        {
            game_matrix[y][x - var]+=1;
        }
        break;
    case 2://up
        std::cout<< "it reaches the case 2"<< std::endl;
        for (int var = 0; var < size; ++var)//0,1,2,3,4->size 5
        {
            game_matrix[y- var][x]+=1;

        }
        break;
    case 3://down
        std::cout<< "it reaches the case 3"<< std::endl;
        for (int var = 0; var < size; ++var)//0,1,2,3,4->size 5
        {

            game_matrix[y+ var][x]+=1;
        }
        break;

    default:
        std::cout<< "wrong rotation variable has been given"<< std::endl;
        break;
    }

}


void Game_Map::display_map()
{
    for (int x = 0; x < 10; ++x)
    {
        for (int y = 0; y < 10; ++y)
        {
            std::cout << game_matrix[x][y];
        }
        std::cout <<std::endl;
    }
}


