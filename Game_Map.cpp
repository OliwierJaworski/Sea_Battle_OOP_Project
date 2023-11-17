#include "Game_Map.h"


//public
    void Game_Map::set_enemy_map(int x, int y)
    {

    }
    const int Game_Map::Player_Life_Left()
    {
        int life=0;
        for (int i = 0; i < BoatsVector.size(); ++i)
        {
            life +=BoatsVector.at(i)->get_Health_Amount();
        }
        return life;
    }

//private
    void Game_Map::Init_Boats()
    {
        Boats_Destroyer* Destroyer =new Boats_Destroyer;
        Boats_Carrier* Carrier = new Boats_Carrier;

        BoatsVector.push_back(Destroyer);
        BoatsVector.push_back(Carrier);
    }
    void Game_Map::Boats_Fill_Map(Game_Boats& Boat_ID)
    {

    }
    void Game_Map::Free_Alloc()
    {

        for (int i = 0; i < BoatsVector.size(); ++i)
        {
            BoatsVector.erase(BoatsVector.begin()+ i);
        }
        BoatsVector.shrink_to_fit();
    }
    void set_map_toempty(int map_to_empty[64][64])
    {
        for (int i = 0; i < 64; ++i)
        {
           std::fill(map_to_empty[i],map_to_empty[i]+64,0);
        }
    }