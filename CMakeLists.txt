cmake_minimum_required(VERSION 3.16)
project(semester2Project C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES semester2Project main.c sortedlist.c LS_allegro.c)
add_executable(semester2Project main.c sortedlist.c LS_allegro.c)

link_directories(allegro-5.0.10/include/allegro5)
include_directories(allegro-5.0.10/addons/font)
include_directories(allegro-5.0.10/addons/primitives/allegro5)
include_directories(allegro-5.0.10/addons/ttf/allegro5)


