cmake_minimum_required(VERSION 3.15)
project(MemoryLists C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/libs)

add_library(singlelinkedlists singlelinkedlists.c singlelinkedlists.h)
add_library(doublylinkedlists doublylinkedlists.c doublylinkedlists.h)
add_library(MemoryLists library.c library.h singlelinkedlists.c singlelinkedlists.h hashtable.c hashtable.h doublylinkedlists.c doublylinkedlists.h linkedlists.h)