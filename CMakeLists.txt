cmake_minimum_required(VERSION 3.26)
project(REMADE_Sea_Battle)

set(CMAKE_CXX_STANDARD 23)

add_executable(REMADE_Sea_Battle main.cpp
        Game_Manager.cpp
        Game_Manager.h
        Game_Player.cpp
        Game_Player.h
        Game_Map.cpp
        Game_Map.h
        Game_Boats.cpp
        Game_Boats.h
        Boats_Destroyer.cpp
        Boats_Destroyer.h
        Boats_Carrier.cpp
        Boats_Carrier.h
        Tcp_Server_Socket.cpp
        Tcp_Server_Socket.h
        Tcp_Client_Socket.cpp
        Tcp_Client_Socket.h
        Game_TCP_Communication.cpp
        Game_TCP_Communication.h
)

