cmake_minimum_required(VERSION 3.6)
project(Grafo_Analisador)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES
        scr/inc/bibliotecas.h scr/inc/structs.h
        scr/tad/node/node.c scr/tad/node/node.h
        scr/tad/lista/lista.c scr/tad/lista/lista.h
        scr/main.c )
add_executable(Grafo_Analisador ${SOURCE_FILES})