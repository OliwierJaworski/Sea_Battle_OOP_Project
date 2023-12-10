#ifndef REMADE_SEA_BATTLE_FIRST_AI_H
#define REMADE_SEA_BATTLE_FIRST_AI_H
#include "Game_Player.h"

class First_AI : public Game_Player
{
private:
    struct AI_Coordinates : Coordinates
    {
        int x=0;
        int y=0;
        int chance_ratio=0;//min 0 - max 100
        int ships_alive[1][5]={TILE_STATE::WATER};//shipsize
    };
               int chance_field[10][10]={0};//displays chances from 0-100
               int biggest_BoatSize();
              bool find_initial_move();
              bool will_boat_fit(int y, int x, int size);
 First_AI::AI_Coordinates PRE_Attack_Enemy(First_AI::AI_Coordinates User_Input_Cords);
    bool chance_calculation();
    AI_Coordinates set_chance_field(int y,int x,int value) {chance_field[y][x]=value;}

public:
    First_AI()=default;
    ~First_AI() override =default;
};

#endif
