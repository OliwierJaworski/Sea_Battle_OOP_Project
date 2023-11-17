cmake_minimum_required(VERSION 3.26)
project(REMADE_Sea_Battle)

set(CMAKE_CXX_STANDARD 23)

add_executable(REMADE_Sea_Battle main.cpp
        Game_Manager.cpp
        Game_Manager.h
        Game_Player.cpp
        Game_Player.h)
