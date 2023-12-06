#ifndef GAME_FROM_SCRATCH_AGAIN_GAME_MANAGER_LOADER_H
#define GAME_FROM_SCRATCH_AGAIN_GAME_MANAGER_LOADER_H
#include <iostream>
#include <memory>
#include <string>

#include "SP_Game_Manager.h"
#include "MP_Game_Manager.h"

class Game_Manager_Loader
{
public:
    Game_Manager_Loader();
    virtual ~Game_Manager_Loader() =default;
private:
    std::unique_ptr<SP_Game_Manager> SP_Game;
    std::unique_ptr<MP_Game_Manager> MP_Game;

    void Game_Type(std::string User_Option);
    std::string Player_Option();
};


#endif
