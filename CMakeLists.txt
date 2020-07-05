cmake_minimum_required(VERSION 3.16)
project(semester2Project C)

set(CMAKE_C_STANDARD 11)
find_package(Threads)

add_executable(semester2Project
        main.c
        view/BitMapViewComponent.c
        view/BitMapViewComponent.h
        view/BoxBoundViewComponent.c
        view/BoxBoundViewComponent.h
        view/ViewComponent.c
        view/ViewComponent.h
        view/ConfigurationPanelComponent.c
        view/ConfigurationPanelComponent.h
        carconfiguration.h
        carconfiguration.c
        category.h
        category.c
        driverconfiguration.c
        driverconfiguration.h
        driverraceresult.c
        driverraceresult.h
        LS_allegro.h
        LS_allegro.c
        main.c
        part.c
        part.h
        raceconfiguration.c
        raceconfiguration.h
        racepoint.c
        racepoint.h
        raceresult.c
        raceresult.h
        simulation.c
        simulation.h
        sortedlist.c
        sortedlist.h
        standing.c
        standing.h
        standings.c
        standings.h
        view/CarBoxComponent.c view/CarBoxComponent.h)


include_directories(/usr/include/allegro5)

target_link_libraries(semester2Project allegro allegro_primitives allegro_image allegro_font allegro_ttf)
target_link_libraries(semester2Project ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(semester2Project m)
