#ifndef REMADE_SEA_BATTLE_GAME_BOATS_H
#define REMADE_SEA_BATTLE_GAME_BOATS_H


class Game_Boats
{

public:
//constructor | destructor
    Game_Boats();
    virtual ~Game_Boats();
//public
    virtual void SpecialMove();
    static void Take_Damage(Game_Boats & boat, int x, int y);
private:
//private
    int Health_Amount;
    int size;
};


#endif
