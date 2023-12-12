#include "First_AI.h"
using namespace AI_Player;

int First_AI::init_boat_sizes()
{
    for (auto boat : Get_map_instance().Get_Boat_Vector())
    {
        boats_left.push_back(boat->Get_Size());
    }
}
int First_AI::find_biggest_boat()
{
    int curr_biggest =0;
    for (auto boatsizes : boats_left)
    {
        if(boatsizes>curr_biggest)
        {
            curr_biggest=boatsizes;
        }
    }
    return curr_biggest;
}
bool First_AI::find_initial_move()
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j< 10; ++j)
        {

            if(Get_map_instance().get_My_Enemy_map(i,j)!=TILE_STATE::WATER)
            {
                return true;
            }
        }
    }
    return false;
}

bool First_AI::boat_fit_combination()
{
    for (int y_curr = 0; y_curr < 10; ++y_curr)
    {
        for (int x_curr = 0; x_curr < 10; ++x_curr)
        {
                for (int rotation = 0; rotation < 4; ++rotation)
                {
                    tile_info::fit_direction fit_tile;
                        switch (rotation)
                        {
                            case Rotation_Direction::TO_RIGHT:

                                for (int size = 0; size < find_biggest_boat(); ++size)
                                {
                                        if(Get_map_instance().get_My_Enemy_map(y_curr,x_curr+size) !=TILE_STATE::WATER)
                                        {
                                            fit_tile.to_right=-1;
                                            fit_tile.curr_dir_boat_fit = false;
                                            chance_field[y_curr][x_curr+size].set_fit_direction(fit_tile);
                                        }
                                }
                                if(fit_tile.curr_dir_boat_fit)
                                {
                                    if(chance_field[y_curr][x_curr+find_biggest_boat()].get_fit_direction().to_left==0 && x_curr+find_biggest_boat() > 0 || x_curr+find_biggest_boat() < 9)
                                    for (int size = 0; size < find_biggest_boat(); ++size)//if boat x,y-boatx,y-boatsize==1 tile has been done to left already
                                    {
                                        fit_tile.to_right=+1;
                                        chance_field[y_curr][x_curr+size].set_fit_direction(fit_tile);
                                    }
                                }
                                break;

                            case Rotation_Direction::TO_LEFT:

                                for (int size = 0; size < find_biggest_boat(); --size)
                                {
                                    if(Get_map_instance().get_My_Enemy_map(y_curr,x_curr+size) !=TILE_STATE::WATER)
                                    {
                                        fit_tile.to_left=-1;
                                        fit_tile.curr_dir_boat_fit = false;
                                        chance_field[y_curr][x_curr+size].set_fit_direction(fit_tile);
                                    }
                                }
                                if(fit_tile.curr_dir_boat_fit)
                                {
                                    if(chance_field[y_curr][x_curr-find_biggest_boat()].get_fit_direction().to_right==0 && x_curr-find_biggest_boat() > 0 || x_curr-find_biggest_boat() < 9)
                                        for (int size = 0; size < find_biggest_boat(); --size)//if boat x,y-boatx,y-boatsize==1 tile has been done to left already
                                        {
                                            fit_tile.to_left=+1;
                                            chance_field[y_curr][x_curr+size].set_fit_direction(fit_tile);
                                        }
                                }
                                break;
                            case Rotation_Direction::UP:
                                for (int size = 0; size < find_biggest_boat(); --size)
                                {
                                    if(Get_map_instance().get_My_Enemy_map(y_curr+size,x_curr) !=TILE_STATE::WATER)
                                    {
                                        fit_tile.up=-1;
                                        fit_tile.curr_dir_boat_fit = false;
                                        chance_field[y_curr+size][x_curr].set_fit_direction(fit_tile);
                                    }
                                }
                                if(fit_tile.curr_dir_boat_fit)
                                {
                                    if(chance_field[y_curr-find_biggest_boat()][x_curr].get_fit_direction().down==0 && y_curr-find_biggest_boat() > 0 || y_curr-find_biggest_boat() < 9)
                                        for (int size = 0; size < find_biggest_boat(); --size)//if boat x,y-boatx,y-boatsize==1 tile has been done to left already
                                        {
                                            fit_tile.up=+1;
                                            chance_field[y_curr+size][x_curr].set_fit_direction(fit_tile);
                                        }
                                }
                                break;

                            case Rotation_Direction::DOWN:

                                for (int size = 0; size < find_biggest_boat(); ++size)
                                {
                                    if(Get_map_instance().get_My_Enemy_map(y_curr+size,x_curr) !=TILE_STATE::WATER)
                                    {
                                        fit_tile.down=-1;
                                        fit_tile.curr_dir_boat_fit = false;
                                        chance_field[y_curr+size][x_curr].set_fit_direction(fit_tile);
                                    }
                                }
                                if(fit_tile.curr_dir_boat_fit)
                                {
                                    if(chance_field[y_curr+find_biggest_boat()][x_curr].get_fit_direction().up==0 && y_curr+find_biggest_boat() > 0 || y_curr+find_biggest_boat() < 9)
                                        for (int size = 0; size < find_biggest_boat(); ++size)//if boat x,y-boatx,y-boatsize==1 tile has been done to left already
                                        {
                                            fit_tile.down=+1;
                                            chance_field[y_curr+size][x_curr].set_fit_direction(fit_tile);
                                        }
                                }
                          break;
                        }
                }
        }
    }
}

