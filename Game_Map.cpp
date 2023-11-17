#include "Game_Map.h"


//public
    Game_Map::Game_Map()
    {
        Init_Boats();

        for (int i = 0; i < BoatsVector.size(); ++i)
        {
            Boats_Fill_Map(*BoatsVector[i]);
        }
    }
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



    bool Game_Map::Boats_Fill_Map(Game_Boats& Boat_ID)
    {
        //check if coordinates are valid-> no boat parts on it, no illegal placements

        int random_index_x;
        int random_index_y;
        int boat_rot;
        bool willfit = false;

        while(!willfit)
        {
            random_index_x= rand()%10;
            random_index_y= rand()%10;
            boat_rot= rand()%4;

            willfit=Will_Boat_Fit(Boat_ID,random_index_x,random_index_y,boat_rot);
        }
        place_boats(Boat_ID, random_index_x, random_index_y, boat_rot);

    }

    bool Game_Map::Will_Boat_Fit(Game_Boats& Boat_ID, int x, int y, int rot)
    {
        int willfit=0;
            switch (rot)
            {
                case 0://to right
                    if(x + Boat_ID.Get_Size() <= 9 )
                    {
                        for (int var = 0; var < Boat_ID.Get_Size() ; ++var)//0,1,2,3,4->size 5
                        {

                            if(My_map[y][x+ var]==0)
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

                case 1://to left
                    if(x - Boat_ID.Get_Size()  >= 0 )
                    {
                        for (int var = 0; var < Boat_ID.Get_Size() ; ++var)//0,1,2,3,4->size 5
                        {

                            if(My_map[y][x - var]==0)
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

                case 2://up
                    if(y - Boat_ID.Get_Size()  >= 0 )
                    {
                        for (int var = 0; var < Boat_ID.Get_Size() ; ++var)//0,1,2,3,4->size 5
                        {
                            if(My_map[y- var][x]==0)
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
                case 3://down
                    if(y + Boat_ID.Get_Size()  <= 9 )
                    {
                        for (int var = 0; var < Boat_ID.Get_Size() ; ++var)
                        {
                            if(My_map[y+ var][x]==0)
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
        else
            return false;
    }

    void Game_Map::place_boats(Game_Boats& Boat_ID, int x, int y, int rot)
    {
        switch (rot)
        {
            case 0://to right
                for (int var = 0; var < Boat_ID.Get_Size() ; ++var)//0,1,2,3,4->size 5
                {
                    My_map[y][x + var]=Boat_ID.Get_Size();
                }
                break;
            case 1://to left
                for (int var = 0; var < Boat_ID.Get_Size() ; ++var)//0,1,2,3,4->size 5
                {
                    My_map[y][x - var]=Boat_ID.Get_Size();
                }
                break;
            case 2://up
                for (int var = 0; var < Boat_ID.Get_Size() ; ++var)//0,1,2,3,4->size 5
                {
                    My_map[y- var][x]=Boat_ID.Get_Size();

                }
                break;
            case 3://down
                for (int var = 0; var < Boat_ID.Get_Size() ; ++var)//0,1,2,3,4->size 5
                {

                    My_map[y+ var][x]=Boat_ID.Get_Size();
                }
                break;

            default:
                std::cout<< "wrong rotation variable has been given"<< std::endl;
                break;
        }
    }
    void Game_Map::Free_Alloc()
    {

        for (int i = 0; i < BoatsVector.size(); ++i)
        {
            BoatsVector.erase(BoatsVector.begin()+ i);
        }
        BoatsVector.shrink_to_fit();
    }
    /*
    void set_map_toempty(int map_to_empty[64][64])
    {
        for (int i = 0; i < 10; ++i)
        {
           std::fill(map_to_empty[i],map_to_empty[i]+10,0);
        }
    }
    */