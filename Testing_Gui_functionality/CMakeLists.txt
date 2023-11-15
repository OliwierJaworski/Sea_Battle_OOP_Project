cmake_minimum_required(VERSION 3.26)
project(Testing_Gui_functionality)

set(CMAKE_CXX_STANDARD 23)

find_package(SFML COMPONENTS graphics window system REQUIRED)

add_executable(Testing_Gui_functionality main.cpp)

target_link_libraries(Testing_Gui_functionality sfml-graphics sfml-window sfml-system)





