cmake_minimum_required(VERSION 3.23)
project(B4ttle C)
set(CMAKE_C_STANDARD 90)

include_directories(.)

add_executable(B4ttle
        display.c
        main.c
        monster.h fromInternet.c)
