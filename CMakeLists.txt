cmake_minimum_required(VERSION 3.6)

project(radiate)

add_subdirectory(src/gmlib)
add_executable(radiate src/main.cpp)

target_link_libraries(radiate gmlib_core)
target_link_libraries(radiate gmlib_obj)
set_property(TARGET radiate PROPERTY CXX_STANDARD 14)
