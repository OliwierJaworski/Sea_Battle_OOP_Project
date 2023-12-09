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
    Game_Boats(int Boat_size, std::string  Boat_name) : Boat_size(Boat_size), Boat_name(Boat_name){Init_Boat_Tiles();}
    virtual ~Game_Boats() =default;

    struct TILE_INFO
    {
        int x;//cords of part of ship
        int y;
        int tile_status = WATER;
        std::shared_ptr<Game_Boats> ship_on_tile = nullptr; //easier way to iterate through ships
    };

    int Get_Size()                         {return Boat_size;}
    std::string Get_Ship_Name()            {return Boat_name;}

protected:
    virtual void SpecialMove() = 0;
    void Init_Boat_Tiles();
    void set_Boat_tile(int x, int y,int IsHit, int ship_part);
    TILE_INFO get_boat_tile(int ship_part)                      {return ship_info[ship_part];}
    void set_Boat_Size(int replace_value)                       {Boat_size= replace_value;}
    void set_Boat_name(std::string new_name)                    {Boat_name=new_name;}

private:
    int Boat_size=0;
    std::string Boat_name;
    std::vector<TILE_INFO> ship_info;
};
#endif
