#ifndef GAME_FROM_SCRATCH_AGAIN_SP_GAME_MANAGER_H
#define GAME_FROM_SCRATCH_AGAIN_SP_GAME_MANAGER_H

#include <iostream>
#include <memory>
#include <string>

#include "../Player_Related/Game_Player.h"
#include "../Player_Related/First_AI.h"
#include "../Player_Related/Simple_Ai.h"

class SP_Game_Manager
{
public:
                  SP_Game_Manager(int player_type1,int player_type2);
                 ~SP_Game_Manager()=default;


        bool Play_Game();
private:
    enum player_types
    {
        real_player,
        Easy_Ai,
        Harder_Ai
    };
    std::vector<Game_Player *> player_vector;

    bool Game_State_active();
    bool Player_Add_ToGame(Game_Player & curr_player, bool identical_players_allowed);
    void chosen_player_init(int player_Typechosen);
    void play_turn(Game_Player * curr_player,Game_Player * enemy_player);
    void answer_AttackReq(Coordinates currP_Attack,Game_Player * curr_player, Game_Player * enemy_player);
};

#endif
