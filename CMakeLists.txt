cmake_minimum_required(VERSION 3.22)
project(B4ttle C)
set(CMAKE_C_STANDARD 90)

include_directories(. )

set(SOURCE_FILES /usr/include/curses.h)

add_executable(B4ttle
        display.c
        main.c
        monster.h
        fromInternet.c
        ${SOURCE_FILES}
        )
