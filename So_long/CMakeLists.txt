cmake_minimum_required(VERSION 3.26)
project(So_long C)

set(CMAKE_C_STANDARD 99)

add_executable(So_long src/main.c
        src/juego.c
        headers/juego.h
        headers/map.h
        src/map.c
        src/element.c
        headers/element.h
        headers/constants.h
        src/file_validator.c
        headers/file_validator.h
        src/get_next_line.c)
