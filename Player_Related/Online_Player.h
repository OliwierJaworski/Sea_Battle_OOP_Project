#ifndef REMADE_SEA_BATTLE_ONLINE_PLAYER_H
#define REMADE_SEA_BATTLE_ONLINE_PLAYER_H

#include "Game_Player.h"
class Online_Player : public Game_Player
{
public:
    Online_Player() =default;
    ~Online_Player() override {};

    std::string Player_Input();
    bool adj_MyMAP_TOResponse(int x, int y);
    Coordinates Attack_Enemy(std::string input_string);
    Coordinates adj_map_ToResponse(int y,int x, bool tile_state);
private:
};


#endif