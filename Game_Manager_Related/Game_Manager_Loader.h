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
                                     Game_Manager_Loader() =default;
                                     ~Game_Manager_Loader() =default;

                                void Game_Type(std::string User_Option);
                         std::string Player_Option();
private:
    std::unique_ptr<SP_Game_Manager> SP_Game = nullptr;
    std::unique_ptr<MP_Game_Manager> MP_Game = nullptr;
                         inline void forward_SP_playgame();
                         inline void forward_MP_playgame();
};
#endif
