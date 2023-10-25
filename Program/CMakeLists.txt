cmake_minimum_required(VERSION 3.26)
project(Project_OOP_2023)

set(CMAKE_CXX_STANDARD 23)

add_executable(Project_OOP_2023 main.cpp
        GameHandler.cpp
        GameHandler.h
        GameMatrix.cpp
        GameMatrix.h
        Game_Map.cpp
        Game_Map.h
        Player.cpp
        Player.h
)
