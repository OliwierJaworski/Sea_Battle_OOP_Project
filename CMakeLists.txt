cmake_minimum_required(VERSION 3.26)
project(REMADE_Sea_Battle)

set(CMAKE_CXX_STANDARD 23)

set(SOURCE_FILES main.cpp
        Game_Manager/Game_Manager.cpp
        Game_Manager/Game_Manager.h
        Player_Related/Game_Player.cpp
        Player_Related/Game_Player.h
        Player_Related/Game_Map.cpp
        Player_Related/Game_Map.h
        Boats_Related/Game_Boats.cpp
        Boats_Related/Game_Boats.h
        Boats_Related/Boats_Destroyer.cpp
        Boats_Related/Boats_Destroyer.h
        Boats_Related/Boats_Carrier.cpp
        Boats_Related/Boats_Carrier.h
        Tcp_Related/Tcp_Server_Socket.cpp
        Tcp_Related/Tcp_Server_Socket.h
        Tcp_Related/Tcp_Client_Socket.cpp
        Tcp_Related/Tcp_Client_Socket.h
        Tcp_Related/Tcp_Client_Socket.cpp
        Game_Manager/Online_Game_Manager.cpp
        Game_Manager/Online_Game_Manager.h
        Game_Manager/Game_Manager_Loader.cpp
        Game_Manager/Game_Manager_Loader.h
        Player_Related/Online_Player.cpp
        Player_Related/Online_Player.h)

add_executable(REMADE_Sea_Battle ${SOURCE_FILES})

target_include_directories(REMADE_Sea_Battle PRIVATE /Boats_Related /Game_Manager /Player_Related /Tcp_Related)

