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

int Game_Map::Calc_Boat_Fit(int x, int y, int size, int boat_rot)
{
    int willfit=0;

    if(x + size < 10 || y + size < 10)
    {
        switch (boat_rot)
        {
        case 0://to right
            for (int var = 0; var < size-1; ++var)//0,1,2,3,4->size 5
            {
                if(game_matrix[x + var][y]==0)
                {
                    willfit=0;
                }
                else
                {
                    willfit+=1;
                }
            }
            break;
        case 1://to left
            for (int var = 0; var < size-1; ++var)//0,1,2,3,4->size 5
            {
                if(game_matrix[x - var][y]==0)
                {
                    willfit=0;
                }
                else
                {
                    willfit+=1;
                }
            }
            break;
        case 2://up
            for (int var = 0; var < size-1; ++var)//0,1,2,3,4->size 5
            {
                if(game_matrix[x][y - var]==0)
                {
                    willfit=0;
                }
                else
                {
                    willfit+=1;
                }
            }
            break;
        case 3://down
            for (int var = 0; var < size-1; ++var)//0,1,2,3,4->size 5
            {
                if(game_matrix[x][y - var]==0)
                {
                    willfit=0;
                }
                else
                {
                    willfit+=1;
                }
            }
            break;

        default:
            std::cout<< "wrong rotation variable has been given"<< std::endl;
            break;
        }
    }
    else`
    {
        return 1;
    }
    return willfit;
}


