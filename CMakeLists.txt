cmake_minimum_required(VERSION 3.26)
project(REMADE_Sea_Battle)

set(CMAKE_CXX_STANDARD 23)

add_executable( REMADE_Sea_Battle main.cpp
                Tcp_Server_Socket.cpp
                Tcp_Server_Socket.h
                Tcp_Client_Socket.cpp
                Tcp_Client_Socket.h
                Game_TCP_Communication.cpp
                Game_TCP_Communication.h

)

