make_minimum_required(VERSION 3.22)
project(stack_li2 C)

set(CMAKE_C_STANDARD 11)

include_directories(code)

add_executable(stack_li2
        code/funcoes.c
        code/main.c
        code/tipos.h)
