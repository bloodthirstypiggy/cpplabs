cmake_minimum_required(VERSION 3.20)
project(lab2)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

enable_testing()

add_executable(lab2
        cissoid.cpp
        cissoid.hpp
        main.cpp
        test.cpp)

add_subdirectory(gtest/googletest-master)

target_link_libraries(lab2 gtest gtest_main)
