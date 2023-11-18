#ifndef REMADE_SEA_BATTLE_GAME_PLAYER_H
#define REMADE_SEA_BATTLE_GAME_PLAYER_H
#include <string>

#include "Game_Map.h"


class Game_Player
{
friend class Game_Manager;

public:
//constructor | destructor
    Game_Player();
    ~Game_Player();
//public
    const Game_Player* Get_This_Player_Id()                                                         const {return this;}
    bool Get_Player_lost();
    bool Did_enemy_hit(int y ,int x);
    bool Did_I_hit(int y ,int x,Game_Player& enemy_player);
    const int Get_friendly_map_loc_value(int x, int y)                                              const {return map->get_my_map(x,y);}
    void Set_enemy_map_hit_attempt(int x,int y,bool hit_or_miss)                                          { return map->set_enemy_map(x,y,hit_or_miss);}
    void Attack_Enemy(Game_Player& current_player, Game_Player& enemy_player );
    void print_map(Game_Map & Used_map,int whichmap);
    int user_input();

private:
//private
    Game_Map * map;
    void Init_Map()  {map = new Game_Map;}
    void Free_Alloc();
};


#endif
