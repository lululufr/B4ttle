cmake_minimum_required(VERSION 3.22)
project(B4ttle C)
set(CMAKE_C_STANDARD 90)

include_directories(. )

set(SOURCE_FILES /usr/include/curses.h menu.h)

add_executable(B4ttle
        main.c
        monster.h
        fromInternet.c
        ${SOURCE_FILES}
        menu.h bibliotheque.h action.h display.h maps/map.h)
