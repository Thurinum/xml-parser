cmake_minimum_required(VERSION 3.25)
project(xml C)

set(CMAKE_C_STANDARD 23)

add_library(xml STATIC xml.c string.c string.h)
