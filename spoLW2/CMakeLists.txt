cmake_minimum_required(VERSION 3.17)
project(LW2 C)

set(CMAKE_C_STANDARD 99)

add_executable(LW2 sources/main.c sources/user_interface.c headers/user_interface.h  headers/commands.h headers/structures.h headers/operations_ext.h sources/filesystem_utils.c headers/filesystem_utils.h sources/commands.c sources/operations_ext.c sources/mode.c headers/mode.h sources/partition.c headers/partition.h headers/state.h sources/main.c headers/constants.h sources/utils.c headers/utils.h)
add_library(extlabutilsextra1 SHARED sources/main.c sources/user_interface.c sources/filesystem_utils.c sources/commands.c sources/operations_ext.c sources/mode.c sources/partition.c sources/utils.c)
target_link_libraries(LW2 PRIVATE extlabutilsextra1)
