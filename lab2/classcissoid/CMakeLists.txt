cmake_minimum_required(VERSION 3.20)
project(classcissoid)

set(CMAKE_CXX_STANDARD 17)

add_library(classcissoid STATIC cissoid.cpp cissoid.hpp)
