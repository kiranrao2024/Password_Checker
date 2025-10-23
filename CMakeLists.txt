cmake_minimum_required(VERSION 3.30)
project(DSAProject2)

set(CMAKE_CXX_STANDARD 20)

add_executable(DSAProject2 main.cpp
        trie.cpp
        trie.h
        HashTable.cpp
        HashTable.h)
