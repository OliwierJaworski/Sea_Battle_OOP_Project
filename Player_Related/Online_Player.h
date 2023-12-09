#ifndef REMADE_SEA_BATTLE_ONLINE_PLAYER_H
#define REMADE_SEA_BATTLE_ONLINE_PLAYER_H

#include "Game_Player.h"
class Online_Player : public Game_Player
{
public:
                Online_Player()  =default;
                ~Online_Player()  override {};

    Coordinates Attack_Enemy(std::string input_string);
           void adj_myEnemymap_ToResponse(int y,int x, bool tile_state);
           bool adj_MyMAP_TOResponse(int y, int x);
private:
    Game_Map map;
};


#endif