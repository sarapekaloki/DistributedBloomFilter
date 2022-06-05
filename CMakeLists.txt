cmake_minimum_required(VERSION 3.17)
project(FiltroBloom)

set(CMAKE_CXX_STANDARD 14)

MATH(EXPR stack_size "16 * 1024 * 1024") # 16 Mb
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")

add_executable(FiltroBloom build/main.cpp include/BloomFilter.cpp include/BloomFilter.h include/Simulation.cpp include/Simulation.h test/test_CheckEquality.cpp test/test_add.cpp test/test_search.cpp test/test_SearchTest.cpp test/test_intesiveAdd.cpp test/blockTest.cpp include/read_Data.cpp include/read_Data.h)
