cmake_minimum_required(VERSION 3.25)
project(demo C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(demo main.c)
target_link_libraries(demo PUBLIC xml)
target_include_directories(demo PUBLIC ../lib)
