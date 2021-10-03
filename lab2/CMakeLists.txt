cmake_minimum_required(VERSION 3.20)
project(lab2)

set(CMAKE_CXX_STANDARD 17)




add_subdirectory(gtest/googletest-master)
add_subdirectory(classcissoid)

add_executable(lab2
        main.cpp
        test.cpp
      test.hpp)

target_link_libraries(lab2 gtest gtest_main classcissoid)
