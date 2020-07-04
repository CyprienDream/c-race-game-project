cmake_minimum_required(VERSION 3.16)
project(semester2Project C)

set(CMAKE_C_STANDARD 11)
find_package(Threads)

add_executable(semester2Project
        main.c
        sortedlist.h
        sortedlist.c
        LS_allegro.h
        LS_allegro.c driverconfiguration.h raceconfiguration.h carconfiguration.h part.h category.h category.c part.c raceconfiguration.c carconficuration.c driverconfiguration.c racepoint.c racepoint.h simulation.h simulation.c driverraceresult.h driverraceresult.c raceresult.h raceresult.c standing.h standing.c standings.h standings.c)

include_directories(/usr/include/allegro5)

target_link_libraries(semester2Project allegro allegro_primitives allegro_image allegro_font allegro_ttf)
target_link_libraries(semester2Project ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(semester2Project m)
