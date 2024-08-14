cmake_minimum_required(VERSION 3.27)
project(SuperHashTable)

set(CMAKE_CXX_STANDARD 17)

add_executable(SuperHashTable main.cpp
        HashTable.h
        HashTable.cpp)
