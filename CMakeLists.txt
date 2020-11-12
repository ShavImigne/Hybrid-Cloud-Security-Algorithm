cmake_minimum_required(VERSION 3.17)
project(INS_project)

set(CMAKE_CXX_STANDARD 14)

add_executable(server Server.cpp)
add_executable(client client.cpp)