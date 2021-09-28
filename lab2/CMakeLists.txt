cmake_minimum_required(VERSION 3.20)
project(lab2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab2
        cissoid.cpp
        cissoid.hpp
        main.cpp
        test.hpp
        test.cpp)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
target_link_libraries(lab2 ${GTEST_LIBRARIES} pthread)
