#ifndef MAPH
#define MAP_H

struct matrix
{
    int matrix_player1[4][4];
    int matrix_player2[4][4];
};

class Map
{
public:
    void init_matrix();
    void init_ships(matrix ship_loc);
private:
    matrix map_matrix;
};

#endif // MAP_H
