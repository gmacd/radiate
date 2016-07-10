cmake_minimum_required(VERSION 3.6)

project(radiate)

add_subdirectory(gmlib)
add_executable(radiate src/main.cpp)

target_link_libraries(radiate gmlib_core)
set_property(TARGET radiate PROPERTY CXX_STANDARD 14)
