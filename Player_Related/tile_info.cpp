#include "tile_info.h"
using namespace AI_Player;
tile_info::tile_info()
{

}
tile_info::~tile_info()
{

}
void tile_info::calculate_direction_sum()
{
    if(boat_dir_fits.to_right==-1 ||boat_dir_fits.to_left==-1 ||boat_dir_fits.up==-1 ||boat_dir_fits.down==-1 )
    {
        direction_sum=-1;
        chance_ratio=-1;
    }
    else
    {
        direction_sum=boat_dir_fits.to_left+boat_dir_fits.to_right+boat_dir_fits.down+boat_dir_fits.up;
    }
}