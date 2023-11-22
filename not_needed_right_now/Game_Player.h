#ifndef REMADE_SEA_BATTLE_GAME_PLAYER_H
#define REMADE_SEA_BATTLE_GAME_PLAYER_H

#include "Game_Map.h"


class Game_Player
{
friend class Game_Manager;

public:
//constructor | destructor
    Game_Player();
    ~Game_Player();

//public
//Player Core structure
    bool Get_Player_Status();
    void Current_Player_Attack_Enemy(Game_Player& current_player, Game_Player& enemy_player );
    bool Get_Enemy_didHit(int y ,int x);
//extra added functionality
    const Game_Player* Get_This_Player_Id()const           {return this;}
    void print_map(Game_Map & Used_map,int whichmap);
    int user_input();

private:
//private
//Player Core structure
    Game_Map * map;
//extra added functionality
//initialization & destruction
    void Init_Map()                                         {map = new Game_Map;}
    void Free_Alloc();
};


#endif
