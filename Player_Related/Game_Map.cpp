#include "Game_Map.h"


//public
    Game_Map::Game_Map()
    {
        Init_Boats();

        for(auto boat : BoatsVector)
        {
            Boats_Fill_Map();
        }
    }

    void Game_Map::set_enemy_map()
    {

    }
    void Game_Map::set_my_map()
    {

    }

//private
    void Game_Map::Init_Boats()
    {
        Boats_Destroyer * Destroyer =new Boats_Destroyer;
        Boats_Carrier * Carrier =new Boats_Carrier;

        BoatsVector.push_back(Destroyer);
        BoatsVector.push_back(Carrier);
    }

    bool Game_Map::Boats_Fill_Map()
    {
        int x;
        int y;
        int rot;

        for (auto boat : BoatsVector)
        {
            do
            {
              x   =rand()%10;
              y   =rand()%10;
              rot =rand()%4;
            }
            while(!Will_Boat_Fit(*boat, x, y, rot));
            place_boats(*boat, x, y, rot);
        }

    }

    bool Game_Map::Will_Boat_Fit(Game_Boats& Boat_ID, int x, int y, int rot)
    {

        int willfit=0;
        switch (rot)
        {
            case TO_RIGHT:
                if(x + Boat_ID.Get_Size() <= 9 )
                {
                    for (int var = 0; var < Boat_ID.Get_Size() ; ++var)//0,1,2,3,4->size 5
                    {

                        if(My_map[y][x+ var].tile_status==WATER)
                        {
                            willfit=0;
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
                else
                {
                    return false;
                }
                break;

            case TO_LEFT:
                if(x - Boat_ID.Get_Size()  >= 0 )
                {
                    for (int var = 0; var < Boat_ID.Get_Size() ; ++var)//0,1,2,3,4->size 5
                    {

                        if(My_map[y][x - var].tile_status==WATER)
                        {
                            willfit=0;
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
                else
                {
                    return false;
                }
                break;

            case UP:
                if(y - Boat_ID.Get_Size()  >= 0 )
                {
                    for (int var = 0; var < Boat_ID.Get_Size() ; ++var)//0,1,2,3,4->size 5
                    {
                        if(My_map[y- var][x].tile_status==WATER)
                        {
                            willfit=0;
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
                else
                {
                    return false;
                }
                break;
            case DOWN:
                if(y + Boat_ID.Get_Size()  <= 9 )
                {
                    for (int var = 0; var < Boat_ID.Get_Size() ; ++var)
                    {
                        if(My_map[y+ var][x].tile_status==WATER)
                        {
                            willfit=0;
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
                else
                {
                    return false;
                }
                break;

            default:
                std::cout<< "wrong rotation variable has been given"<< std::endl;
                break;
        }
        if(willfit==0)
        {
            return true;
        }
    }
    void Game_Map::place_boats(Game_Boats& Boat_ID, int x, int y, int rot)
    {
        switch (rot)
        {
            case TO_RIGHT:
                for (int current_size = 0; current_size < Boat_ID.Get_Size(); ++current_size)
                {
                    Boat_ID.set_ship_tile(x+current_size,y,SHIP,current_size);
                    My_map[x + current_size][y].tile_status=SHIP;
                    My_map[x + current_size][y].ship_on_tile = std::make_shared<* Game_Boats>(Boat_ID).get();

                }
                return;
            case TO_LEFT:
                for (int current_size = 0; current_size < Boat_ID.Get_Size(); ++current_size)
                {
                    Boat_ID.set_ship_tile(x-current_size,y,SHIP,current_size);
                    My_map[x - current_size][y].tile_status=SHIP;
                    My_map[x - current_size][y].ship_on_tile = std::make_shared<* Game_Boats>(Boat_ID).get();
                }
                return;
            case UP:
                for (int current_size = 0; current_size < Boat_ID.Get_Size(); ++current_size)
                {
                    Boat_ID.set_ship_tile(x,y-current_size,SHIP,current_size);
                    My_map[x][y - current_size].tile_status=SHIP;
                    My_map[x][y - current_size].ship_on_tile = std::make_shared<* Game_Boats>(Boat_ID).get();
                }
                return;
            case DOWN:
                for (int current_size = 0; current_size < Boat_ID.Get_Size(); ++current_size)
                {
                    Boat_ID.set_ship_tile(x,y+current_size,SHIP,current_size);
                    My_map[x][y + current_size].tile_status=SHIP;
                    My_map[x][y + current_size].ship_on_tile = std::make_shared<* Game_Boats>(Boat_ID).get();
                }
                return;
        }
    }

    void Game_Map::Free_Alloc()
    {
        for (int i = 0; i < BoatsVector.size(); ++i)
        {
            delete BoatsVector[i]; //erase verwijderd enkel u pointer uit de vector die cleared de memory niet!
            BoatsVector.erase(BoatsVector.begin()+ i);
        }
        BoatsVector.shrink_to_fit();
    }


    