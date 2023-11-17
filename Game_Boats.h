#ifndef REMADE_SEA_BATTLE_GAME_BOATS_H
#define REMADE_SEA_BATTLE_GAME_BOATS_H

#include <vector>
#include <string>
#include <iostream>

class Game_Boats
{

public:
//constructor | destructor
    Game_Boats() : size(0) {}
    virtual ~Game_Boats() = 0;
//public
    virtual void SpecialMove() = 0;
    void Take_Damage(Game_Boats & boat, int x, int y);
    int get_Health_Amount ()                                                                     {return Health_Amount;}
    int Get_Size()                                                                               {return size;}
private:
//private

protected:
//protected
     int Health_Amount;
    int size;
};


#endif
