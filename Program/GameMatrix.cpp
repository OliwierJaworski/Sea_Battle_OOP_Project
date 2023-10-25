//
// Created by oliwier-desktop on 25/10/23.
//
#include <iostream>
#include "GameMatrix.h"

void GameMatrix::Init_Board()
{
    for(int i=0; i<4; i++)
    {
        for(int j=0;j<4;j++)
        {
            SharedMap[i][j]='~';
        }
    }
}

void GameMatrix::print_MapViewMatrix()
{
    for(int i=0; i<4; i++)
    {
        for(int j=0;j<4;j++)
        {
            std::cout << SharedMap[i][j];
        }
        std::cout << std::endl;
    }
}