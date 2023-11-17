#ifndef REMADE_SEA_BATTLE_GAME_PLAYER_H
#define REMADE_SEA_BATTLE_GAME_PLAYER_H


class Game_Player
{

public:
//constructor | destructor
    Game_Player();
    ~Game_Player();
//public
    void Get_PLayer_Id(this);
    bool Get_Player_lost();
    int Get_friendly_map_loc_value();
    void Attack_Enemy(int x, int y, Game_Player& current_player, Game_Player& enemy_player );

private:
//private
    Game_Map * map;
    void Free_Space();
    void Init_map();
};


#endif
