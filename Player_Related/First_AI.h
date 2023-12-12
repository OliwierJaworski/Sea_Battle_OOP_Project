#ifndef REMADE_SEA_BATTLE_FIRST_AI_H
#define REMADE_SEA_BATTLE_FIRST_AI_H
#include "tile_info.h"
#include <cmath>
namespace AI_Player
{
    class First_AI : public Game_Player
   {
    private:
        tile_info chance_field[10][10];
        std::vector<int> boats_left;
        void init_boat_sizes();
        bool find_initial_move();
        bool boat_fit_combination();
        int find_biggest_boat();
        void print_chance_field_chance_values();
    public:
        First_AI() = default;
        ~First_AI() override = default;
    };
}

#endif
