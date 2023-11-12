cmake_minimum_required(VERSION 3.26)
project(Testing_Gui_functionality)

set(CMAKE_CXX_STANDARD 23)

find_package(glfw3 REQUIRED)

add_executable(Testing_Gui_functionality main.cpp glad.c)

target_link_libraries(Testing_Gui_functionality PRIVATE glfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl)





