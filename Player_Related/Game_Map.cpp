#include "Game_Map.h"
//public
    Game_Map::Game_Map()
    {
        Init_Boats();
        Boats_Fill_Map();
    }

//private
    void Game_Map::Init_Boats()
    {
        Boats_Destroyer * Destroyer =new Boats_Destroyer;
        Boats_Carrier * Carrier =new Boats_Carrier;
        Boats_Battleship * Battleship = new Boats_Battleship();
        Boats_Submarine * Submarine =new Boats_Submarine;
        Boats_Patrol_Boat * Patrol_Boat =new Boats_Patrol_Boat;

        BoatsVector.push_back(Destroyer);
        BoatsVector.push_back(Carrier);
        BoatsVector.push_back(Battleship);
        BoatsVector.push_back(Submarine);
        BoatsVector.push_back(Patrol_Boat);
    }

    bool Game_Map::Boats_Fill_Map()
    {
        int x=0;
        int y=0;
        int rot=0;
        for(auto cur_boat : BoatsVector)
        {
            do
            {
                x = rand() % 10;
                y = rand() % 10;
                rot = rand() % 4;
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
                    return check_if_fit(Boat_ID.Get_Size(), y, x, 1, TO_RIGHT);

                case TO_LEFT:
                    return check_if_fit(Boat_ID.Get_Size(), y, x, -1, TO_LEFT);

                case UP:
                    return check_if_fit(Boat_ID.Get_Size(), y, x, -1, UP);

                case DOWN:
                    return check_if_fit(Boat_ID.Get_Size(), y, x, 1, DOWN);
            }
    }

    const bool Game_Map::check_if_fit(int boatsize,int y, int x,int rotation_Operator, int rotation)
    {
        for (int curr_size = 0; curr_size < boatsize && curr_size > -boatsize; curr_size += rotation_Operator)
        {
            switch (rotation)
            {
                case TO_RIGHT:
                case TO_LEFT:
                    if (My_map[y][x + curr_size] != WATER || x + curr_size > 9 || x + curr_size < 0)
                    {
                        return false;
                    }
                    break;
                case UP:
                case DOWN:
                    if (My_map[y + curr_size][x] != WATER || y + curr_size > 9 || y + curr_size < 0)
                    {
                        return false;
                    }
                    break;
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
                 Boat_ID.set_Boat_tile(x+ shippart,y,SHIP,shippart);
                 break;
             case TO_LEFT:
                 My_map[y][x - shippart] = SHIP;
                 Boat_ID.set_Boat_tile(x- shippart,y,SHIP,shippart);
                 break;
             case UP:
                 My_map[y - shippart][x] = SHIP;
                 Boat_ID.set_Boat_tile(x,y- shippart,SHIP,shippart);
                 break;
             case DOWN:
                 My_map[y + shippart][x] = SHIP;
                 Boat_ID.set_Boat_tile(x,y+ shippart,SHIP,shippart);
                 break;
         }
        }
    }

    void Game_Map::print_map()
    {
                std::cout << "my map"<< "                       " << "my enemy map"<<std::endl;
                std::cout << " 0 1 2 3 4 5 6 7 8 9"<< "          " << " 0 1 2 3 4 5 6 7 8 9"<<std::endl;
                for (int i = 0; i < 10; ++i)
                {
                    std::cout << i ;
                    for (int j = 0; j < 10; ++j)
                    {
                        if (My_map[i][j]==WATER)
                        {
                            std::cout << "\U0001F7E6";
                        }
                        if(My_map[i][j]==SHIP)
                        {
                            std::cout << "\U0001F532";
                        }
                        if (My_map[i][j]==MISS)
                        {
                            std::cout << "\U0001F4A6";
                        }
                        if (My_map[i][j]==HIT)
                        {
                            std::cout << "\U0001F525";
                        }
                    }
                    std::cout << "         ";
                    std::cout << i ;
                    for (int j = 0; j < 10; ++j)
                    {
                        if (Enemy_map[i][j]==WATER)
                        {
                            std::cout << "\U0001F7E6";
                        }
                        if(Enemy_map[i][j]==SHIP)
                        {
                            std::cout << "\U0001F532";
                        }
                        if (Enemy_map[i][j]==MISS)
                        {
                            std::cout << "\U0001F4A6";
                        }
                        if (Enemy_map[i][j]==HIT)
                        {
                            std::cout << "\U0001F525";
                        }

                    }
                    std::cout << std::endl;
                }
                std::cout << std::endl;
    }
    int Game_Map::cummulated_boat_size()
    {
        int totaltilesize =0;
        for (auto & boat : BoatsVector)
        {
            totaltilesize +=boat->Boat_size;
        }
        return totaltilesize;

    }

    bool Game_Map::any_ship_alive()
    {
        int hits=0;
        for(auto boat : BoatsVector)
        {
            for (int curr_tile=0; curr_tile < boat->Boat_size ; curr_tile++)
            {
                if(boat->get_boat_tile(curr_tile).tile_status==HIT)
                {
                    hits++;
                }
            }
        }
       if(hits == cummulated_boat_size())
       {
           return false;
       }
       else
           return true;
    }
    bool Game_Map::get_my_map(int y,int x )
    {
        if(My_map[y][x]==WATER)
        {
            My_map[y][x]=MISS;
            return false;
        }
        if(My_map[y][x]==SHIP ||My_map[y][x]==HIT)//nu kan de Gehitte tile nog worden opnieuw gehit ga het aanpassen
        {
            My_map[y][x]=HIT;
            Damage_ship(y,x);
            return true;
        }
        else
            return false;
    }
    void Game_Map::Damage_ship(int y, int x)
    {
        for(auto boat : BoatsVector)
        {
            for (int curr_tile = 0; curr_tile < boat->Get_Size(); ++curr_tile)
            {
                if( boat->get_boat_tile(curr_tile).x == x && boat->get_boat_tile(curr_tile).y == y)
                {
                    boat->set_Boat_tile(x,y,HIT,curr_tile);
                }
            }
        }
    }
    void  Game_Map::Set_Enemy_map(int x, int y, bool is_Hit)
    {
        if(is_Hit)
        {
            Enemy_map[y][x]=HIT;
        }
        else
            Enemy_map[y][x]=MISS;
    }
    void Game_Map::Free_Alloc()
    {
        for (int i = 0; i < BoatsVector.size(); ++i)
        {
            delete BoatsVector[i];
            BoatsVector.erase(BoatsVector.begin()+ i);
        }
        BoatsVector.shrink_to_fit();
    }


