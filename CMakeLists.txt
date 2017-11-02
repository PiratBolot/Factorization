cmake_minimum_required(VERSION 3.8)
project(Pollard_s_rho_algorithm)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Factorizator.cpp Factorizator.h)
add_executable(Pollard_s_rho_algorithm ${SOURCE_FILES})