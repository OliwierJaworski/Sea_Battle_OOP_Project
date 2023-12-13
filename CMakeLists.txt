cmake_minimum_required(VERSION 3.26)
project(Zeeslag_Code_Fixing)

set(CMAKE_CXX_STANDARD 23)

find_package(nlohmann_json CONFIG REQUIRED)

add_executable(Zeeslag_Code_Fixing main.cpp
        Game_Manager_Related/Game_Manager_Loader.h
        Game_Manager_Related/MP_Game_Manager.h
        Game_Manager_Related/SP_Game_Manager.h
        Game_Manager_Related/Game_Manager_Loader.cpp
        Game_Manager_Related/MP_Game_Manager.cpp
        Game_Manager_Related/SP_Game_Manager.cpp
        Player_Related/Online_Player.h
        Player_Related/Game_Player.h
        Player_Related/Game_Map.h
        Player_Related/Game_Map.cpp
        Player_Related/Game_Player.cpp
        Player_Related/Online_Player.cpp
        Boats_Related/Boats_Carrier.cpp
        Boats_Related/Boats_Carrier.h
        Boats_Related/Boats_Destroyer.cpp
        Boats_Related/Boats_Destroyer.h
        Boats_Related/Game_Boats.cpp
        Boats_Related/Game_Boats.h
        TCP_Connection/Tcp_Client_Socket.cpp
        TCP_Connection/Tcp_Server_Socket.cpp
        TCP_Connection/Tcp_Client_Socket.h
        TCP_Connection/Tcp_Server_Socket.h
        TCP_Connection/TCP_SHARED.cpp
        TCP_Connection/TCP_SHARED.h
        Boats_Related/Boats_Battleship.cpp
        Boats_Related/Boats_Battleship.h
        Boats_Related/Boats_Submarine.cpp
        Boats_Related/Boats_Submarine.h
        Boats_Related/Boats_Patrol_Boat.cpp
        Boats_Related/Boats_Patrol_Boat.h
        Player_Related/First_AI.cpp
        Player_Related/First_AI.h
        Player_Related/tile_info.cpp
        Player_Related/tile_info.h
        Player_Related/Simple_Ai.cpp
        Player_Related/Simple_Ai.h)

target_link_libraries(Zeeslag_Code_Fixing PRIVATE nlohmann_json::nlohmann_json)