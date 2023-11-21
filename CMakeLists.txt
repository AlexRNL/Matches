cmake_minimum_required(VERSION 3.25)
project(matches-sdl C)

set(CMAKE_C_STANDARD 11)

add_executable(${PROJECT_NAME})
#target_compile_options(${PROJECT_NAME} PRIVATE -Werror -Wall -Wextra -pedantic-errors -Wconversion -Wsign-conversion)
add_subdirectory(src)
