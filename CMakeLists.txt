cmake_minimum_required(VERSION 3.15)
project(MemoryLists C)

set(CMAKE_C_STANDARD 99)

add_library(MemoryLists library.c library.h linkedlists.c linkedlists.h hashtable.c hashtable.h)