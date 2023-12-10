#include "First_AI.h"
int First_AI::biggest_BoatSize()
{
    int biggest_boat_size=0;
    for (auto boat : Get_map_instance().Get_Boat_Vector())
    {
        if(boat->Get_Size()>biggest_boat_size)
        {
            biggest_boat_size=boat->Get_Size();
        }
    }
    return biggest_boat_size;
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
bool First_AI::chance_calculation()//calculate chance per tile
{
    if (!find_initial_move())
    {
        chance_field[0][0]=100;//no initial move cant measure chances
        return true;
    }
    else
    {//1 tile is minsten positief->hit/miss/boat
    //for every tile
    //->check if boat fits in every rotation
    //->check if boat fits with middle
    //determine the chance
    }
}
First_AI::AI_Coordinates First_AI::PRE_Attack_Enemy(First_AI::AI_Coordinates User_Input_Cords)
{

}
bool First_AI::will_boat_fit(int y, int x, int size)
{
    int rotation=Rotation_Direction::TO_RIGHT;
    switch(rotation)
    {
        case Rotation_Direction::TO_RIGHT:
            rotation_check(y,x)
        case Rotation_Direction::TO_LEFT:
        case Rotation_Direction::UP:
        case Rotation_Direction::DOWN:
    }
}
bool rotation_check(int y ,int x, int rotation , int size)
{
        for (int i = 0; i < size; i+=rotation)
        {
            for (int j = 0; j < ; ++j)
            {

            }
        }


}
