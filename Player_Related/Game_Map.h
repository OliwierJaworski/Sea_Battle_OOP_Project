#ifndef REMADE_SEA_BATTLE_GAME_MAP_H
#define REMADE_SEA_BATTLE_GAME_MAP_H

#include <vector>
#include <string>
#include <iostream>
#include <memory>

#include "../Boats_Related/Boats_Carrier.h"
#include "../Boats_Related/Boats_Destroyer.h"
#include "../Boats_Related/Boats_Battleship.h"
#include "../Boats_Related/Boats_Submarine.h"
#include "../Boats_Related/Boats_Patrol_Boat.h"
#include "../Boats_Related/Game_Boats.h"



class Game_Map
{

public:
//constructor | destructor
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
                         Game_Map();
                         ~Game_Map() {Free_Alloc();};
                  struct Coordinates
                       {
                            int x;
                            int y;
                            bool tile_state;
                       };

                     bool get_my_map(int y, int x) ;
                     void Set_Enemy_map(int x, int y, bool is_Hit);
                      int get_My_Enemy_map(int y, int x) {return Enemy_map[y][x];}
                     void print_map();
                      int cummulated_boat_size();
                     bool any_ship_alive();
const std::vector<Game_Boats *> Get_Boat_Vector() {return BoatsVector;}
private:
std::vector<Game_Boats *> BoatsVector;
                      int My_map[10][10];
                      int Enemy_map[10][10];

                     void Init_Boats();
                     bool Boats_Fill_Map();
                     bool Will_Boat_Fit(Game_Boats& Boat_ID, int y, int x, int rot);
                     bool check_if_fit(int boatsize,int y, int x,int rotation_Operator,int rotation);
                     void place_boats(Game_Boats& Boat_ID, int y, int x, int rot);
                     void Damage_ship(int y, int x);
                     void Free_Alloc();

};
                    using Coordinates = Game_Map::Coordinates;
                    using TILE_STATE = Game_Map::TILE_STATE;
                    using Rotation_Direction = Game_Map::Rotation_Direction;
#endif
