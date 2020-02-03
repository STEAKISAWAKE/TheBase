cmake_minimum_required(VERSION 3.9)

project( TheBase VERSION 0.0.1 DESCRIPTION "The base library for games")

add_library(TheBase SHARED
    src/animation.cpp
    src/buffers.cpp
)