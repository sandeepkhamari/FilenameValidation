cmake_minimum_required(VERSION 3.15)
project(FilenameValidator VERSION 1.0)

add_subdirectory(src)
add_subdirectory(test)

enable_testing()
include(CTest)
