#ifndef GAME_FROM_SCRATCH_AGAIN_MP_GAME_MANAGER_H
#define GAME_FROM_SCRATCH_AGAIN_MP_GAME_MANAGER_H

#include "SP_Game_Manager.h"

class MP_Game_Manager : public SP_Game_Manager
{
public:
    MP_Game_Manager() {std::cout << "MP constructor";}
    ~MP_Game_Manager() override =default;
private:
};

#endif
