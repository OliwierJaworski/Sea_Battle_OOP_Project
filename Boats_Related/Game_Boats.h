#ifndef REMADE_SEA_BATTLE_GAME_BOATS_H
#define REMADE_SEA_BATTLE_GAME_BOATS_H

#include <vector>
#include <string>
#include <iostream>
#include <memory>

enum TILE_STATE
{
    WATER,
    HIT,
    SHIP,
    MISS,
    WAS_ALREADY_HIT
};
enum Rotation_Direction
{
    TO_RIGHT,
    TO_LEFT,
    UP,
    DOWN
};

class Game_Boats
{
friend class Game_Map;
public:
    Game_Boats() : Boat_size(0){}
    virtual ~Game_Boats() {};

    struct TILE_INFO
    {
        int x;//cords of part of ship
        int y;
        int tile_status = WATER;
        std::shared_ptr<Game_Boats> ship_on_tile = nullptr; //easier way to iterate through ships
    };

    int Get_Size()                         {return Boat_size;}
protected:
    int Boat_size;
    std::string ship_name;

    virtual void SpecialMove() = 0;
    std::string Get_Ship_Name()            {return ship_name;}
    std::vector<std::unique_ptr<TILE_INFO>> ship_info;
    void shipvector_element_amount();
    void set_ship_tile(int x, int y,int IsHit, int ship_part);
private:
};
#endif
