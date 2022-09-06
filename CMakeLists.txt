cmake_minimum_required(VERSION 3.10)
project(MemoryLists C)

set(CMAKE_C_STANDARD 99)

set (CMAKE_C_COMPILER "clang")

set(CMAKE_C_FLAGS "-O3 -pg -std=c11 -Wall -Wextra -Wpedantic -Wformat=2 -Wno-unused-parameter -Wshadow -Wwrite-strings -Wstrict-prototypes -Wold-style-definition -Wredundant-decls -Wnested-externs -Wmissing-include-dirs -fno-omit-frame-pointer -fsanitize=address")
set(CMAKE_CXX_FLAGS "-O3 -pg -Wall -Wextra -Wpedantic -Wformat=2 -Wno-unused-parameter -Wshadow -Wwrite-strings -Wstrict-prototypes -Wold-style-definition -Wredundant-decls -Wnested-externs -Wmissing-include-dirs -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/libs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/libs)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/libs)

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

add_library(singlelinkedlists STATIC basic-structures/singlelinkedlists.c basic-structures/singlelinkedlists.h)
add_library(doublylinkedlists STATIC basic-structures/doublylinkedlists.c basic-structures/doublylinkedlists.h)
add_library(vector STATIC basic-structures/doublylinkedlists.c basic-structures/doublylinkedlists.h vector.c vector.h)
add_library(dynamic_array STATIC basic-structures/dynamic_array.c basic-structures/dynamic_array.h)
#add_dependencies(vector doublylinkedlists)
#target_link_libraries(vector ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libdoublylinkedlists.a)

add_library(singlelinkedlistsshared SHARED basic-structures/singlelinkedlists.c basic-structures/singlelinkedlists.h)
add_library(doublylinkedlistsshared SHARED basic-structures/doublylinkedlists.c basic-structures/doublylinkedlists.h)
add_library(vectorshared SHARED basic-structures/doublylinkedlists.c basic-structures/doublylinkedlists.h vector.c vector.h)
add_library(dynamic_array_shared SHARED basic-structures/dynamic_array.c basic-structures/dynamic_array.h)
#add_dependencies(vectorshared doublylinkedlists)
#target_link_libraries(vectorshared ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libdoublylinkedlists.a)

set_target_properties(singlelinkedlistsshared PROPERTIES OUTPUT_NAME singlelinkedlists)
set_target_properties(doublylinkedlistsshared PROPERTIES OUTPUT_NAME doublylinkedlists)
set_target_properties(vectorshared PROPERTIES OUTPUT_NAME vector)
set_target_properties(dynamic_array_shared PROPERTIES OUTPUT_NAME dynamic_array)

add_executable(doublylinkedlist_unittest unittests/doublylinkedliststest.c)
add_dependencies(doublylinkedlist_unittest doublylinkedlists)
target_link_libraries(doublylinkedlist_unittest ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libdoublylinkedlists.a)

add_executable(vector_unittest unittests/vectortest.c)
add_dependencies(vector_unittest vector)
target_link_libraries(vector_unittest ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libvector.a)

add_executable(dynamic_array_unittest unittests/dynamic_array_test.c)
add_dependencies(dynamic_array_unittest dynamic_array)
target_link_libraries(dynamic_array_unittest ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libdynamic_array.a)

#set_source_files_properties(unittests/std_list.cpp PROPERTIES LANGUAGE CXX)
#add_executable(std_list_unittest unittests/std_list.cpp)
#add_library(MemoryLists basic-structures/library.c basic-structures/library.h basic-structures/singlelinkedlists.c basic-structures/singlelinkedlists.h basic-structures/hashtable.c basic-structures/hashtable.h basic-structures/doublylinkedlists.c basic-structures/doublylinkedlists.h basic-structures/linkedlists.h)
