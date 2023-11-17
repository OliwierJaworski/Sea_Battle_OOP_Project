#ifndef REMADE_SEA_BATTLE_GAME_PLAYER_H
#define REMADE_SEA_BATTLE_GAME_PLAYER_H

#include "Game_Map.h"

class Game_Player
{

public:
//constructor | destructor
    Game_Player();
    ~Game_Player();
//public
    const Game_Player* Get_This_Player_Id()                                                         const {return this;}
    bool Get_Player_lost();
    const int Get_friendly_map_loc_value(int x, int y)                                              const {return map->get_my_map(x,y);}
    void Attack_Enemy(int x, int y, Game_Player& current_player, Game_Player& enemy_player );
    void print_player_map(Game_Map & my_map);
private:
//private
    Game_Map * map;
    void Init_Map()  {map = new Game_Map;}
    void Free_Alloc();
};


#endif
