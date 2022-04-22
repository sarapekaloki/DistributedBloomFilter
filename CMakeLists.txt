cmake_minimum_required(VERSION 3.21)
project(BloomFilter)

set(CMAKE_CXX_STANDARD 14)

add_executable(BloomFilter include/BloomFilter.cpp include/BloomFilter.h test/prueba_add.cpp test/prueba_search.cpp include/Simulation.cpp include/Simulation.h build/main.cpp test/prueba_CheckEquality.cpp test/prueba_searchTest.cpp)
