cmake_minimum_required(VERSION 3.20)
project(ternaryvector)

set(CMAKE_CXX_STANDARD 17)

add_library(ternaryvector STATIC vector.cpp vector.hpp)
