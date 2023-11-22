cmake_minimum_required(VERSION 3.8)

project(Matrix LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_EXTENSIONS OFF)

find_package(GTest REQUIRED)
enable_testing()

add_subdirectory(./src)

add_subdirectory(./tests)

target_include_directories(matrix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

target_include_directories(unit PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

target_include_directories(ete PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)