cmake_minimum_required(VERSION 3.17)
project(advent_learn)
ENABLE_TESTING()
set(CMAKE_CXX_STANDARD 20)

add_executable(advent_learn main.cpp)
add_executable(tester test/tests.cpp)
add_test(Tester tester)
