cmake_minimum_required(VERSION 3.20)
project(without_stdlibs)

set(CMAKE_CXX_STANDARD 14)

add_executable(without_stdlibs main.cpp NewArray.cpp NewArray.h HashTables.cpp HashTables.h Queue.cpp Queue.h HashNode.h HashNode.cpp)
