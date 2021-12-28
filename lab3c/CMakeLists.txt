cmake_minimum_required(VERSION 3.16)
project(lab2)

set(CMAKE_CXX_STANDARD 17)


add_subdirectory(ternaryvector)
add_subdirectory(googletest)

add_executable(lab3
        main.cpp
        tests/test.cpp
        )

target_link_libraries(lab3 ternaryvector gtest gtest_main)
