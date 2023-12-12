#ifndef REMADE_SEA_BATTLE_FIRST_AI_H
#define REMADE_SEA_BATTLE_FIRST_AI_H
#include "Game_Player.h"
#include "tile_info.h"
#include <cmath>
namespace AI_Player
{
    class First_AI : public Game_Player
   {
    private:
        tile_info chance_field[10][10];
        std::vector<int> boats_left;
        int init_boat_sizes();
        bool find_initial_move();
        bool chance_calculation(int boatsize);
        int find_biggest_boat();
    public:
        First_AI() = default;
        ~First_AI() override = default;
    };
}

#endif
