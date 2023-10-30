#include "game_map.h"
#include "boats.h"
#include <time.h>

void Game_Map::init_matrix()
{
    for (int x = 0; x < 3; ++x)
    {
        for (int y = 0; y < 3; ++y)
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

