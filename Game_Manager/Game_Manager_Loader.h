#ifndef REMADE_SEA_BATTLE_GAME_MANAGER_LOADER_H
#define REMADE_SEA_BATTLE_GAME_MANAGER_LOADER_H

#include "Game_Manager.h"
#include "Online_Game_Manager.h"

class Game_Manager_Loader
{
public:
    Game_Manager_Loader();
    ~Game_Manager_Loader();
private:
    enum Game_Types{SinglePlayer, Multiplayer};
    std::unique_ptr<Game_Manager> SP_game = nullptr;
    std::unique_ptr<Online_Game_Manager> ONL_game = nullptr;

    void Game_Type(std::string User_Option);
    std::string Player_Option();
};


#endif //REMADE_SEA_BATTLE_GAME_MANAGER_LOADER_H
