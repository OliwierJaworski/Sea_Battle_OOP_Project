#include "map.h"

void Map::init_matrix()
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            Map::map_matrix.matrix_player1[i][j]=0;
            Map::map_matrix.matrix_player2[i][j]=0;
        }
    }
}

void init_ships(matrix ship_loc)
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {

        }
    }
}
