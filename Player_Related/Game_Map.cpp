#include "Game_Map.h"
//public
    Game_Map::Game_Map()
    {
        Init_Boats();
        Boats_Fill_Map();
        print_map();
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
        int x=0;
        int y=0;
        int rot=0;
        for(auto cur_boat : BoatsVector)
        {
            std::cout <<"reached Boats_Fill_Map" <<std::endl;
            do
            {
                x = rand() % 10;
                y = rand() % 10;
                rot = rand() % 4;
                std::cout << "rot :" << rot << " y :" << y << " x :" << x << std::endl;
            }
            while (!Will_Boat_Fit(* cur_boat, y, x, rot));
            place_boats(* cur_boat,y,x,rot);
        }
        return true;
    }

    bool Game_Map::Will_Boat_Fit(Game_Boats& Boat_ID, int y, int x, int rot)
    {
        switch (rot)
        {
            case TO_RIGHT:
                check_if_fit(Boat_ID.Get_Size(),y,x,1,TO_RIGHT);
                break;
            case TO_LEFT:
                check_if_fit(Boat_ID.Get_Size(),y,x,-1,TO_LEFT);
                break;
            case UP:
                check_if_fit(Boat_ID.Get_Size(),y,x,-1,UP);
                break;
            case DOWN:
                check_if_fit(Boat_ID.Get_Size(),y,x,1,DOWN);
                break;
        }
    }
    bool Game_Map::check_if_fit(int boatsize,int y, int x,int rotation_Operator, int rotation)
    {
        for (int curr_size = 0; curr_size < boatsize && curr_size > -boatsize ; curr_size+=rotation_Operator)
        {
            switch (rotation)
            {
                case TO_RIGHT:
                case TO_LEFT:
                        if (My_map[y][x+ curr_size] != WATER || x+ curr_size>9 || x+ curr_size<0)
                        {
                            std::cout << "cant place because  x :" << x+curr_size << "for boat of size : "<< boatsize << std::endl;
                            return false;
                        }
                    break;
                case UP:
                case DOWN:
                        if (My_map[y+ curr_size][x] != WATER || y+ curr_size>9 || y+ curr_size<0)
                        {
                            std::cout << "cant place because  y :" << y+curr_size << std::endl;
                            return false;
                        }
                        break;
                default:
                    std::cerr << "Error: no default value for rotation operator" << std::endl;
            }
        }
        return true;
    }
    void Game_Map::place_boats(Game_Boats& Boat_ID, int y, int x, int rot)
    {
        for (int shippart = 0; shippart < Boat_ID.Get_Size(); ++shippart)
        {
         switch (rot)
         {                               
             case TO_RIGHT:
                 My_map[y][x + shippart ] = SHIP;
                 Boat_ID.set_ship_tile(x+ shippart,y,SHIP,shippart);
                 break;
             case TO_LEFT:
                 My_map[y][x - shippart] = SHIP;
                 Boat_ID.set_ship_tile(x- shippart,y,SHIP,shippart);
                 break;
             case UP:
                 My_map[y - shippart][x] = SHIP;
                 Boat_ID.set_ship_tile(x,y- shippart,SHIP,shippart);
                 break;
             case DOWN:
                 My_map[y + shippart][x] = SHIP;
                 Boat_ID.set_ship_tile(x,y+ shippart,SHIP,shippart);
                 break;
         }
        }
    }
void Game_Map::print_map()
{
            std::cout << "my map"<<std::endl;
            for (int i = 0; i < 10; ++i)
            {
                for (int j = 0; j < 10; ++j)
                {
                    if (get_my_map(i,j)==WATER)
                    {
                        std::cout << "\U0001F7E6";
                    }
                    if(get_my_map(i,j)==SHIP)
                    {
                        std::cout << "\U0001F532";
                    }
                    if (get_my_map(i,j)==HIT)
                    {
                        std::cout << "\U0001F4A6";
                    }
                    if (get_my_map(i,j)==MISS)
                    {
                        std::cout << "\U0001F525";
                    }

                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
            std::cout << std::endl;
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


    