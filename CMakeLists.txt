cmake_minimum_required(VERSION 3.12)
project(HashTable C)

set(CMAKE_C_STANDARD 11)

add_executable(HashTable main.c hashTable.c hashTable.h)