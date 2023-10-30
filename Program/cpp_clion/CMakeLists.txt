cmake_minimum_required(VERSION 3.26)
project(Project_OOP_2023)

set(CMAKE_CXX_STANDARD 23)

add_executable(Project_OOP_2023 main.cpp
        Player.cpp
        Player.h
        Map.cpp
        Map.h
        rules.cpp
        rules.h
)
