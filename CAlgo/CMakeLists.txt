cmake_minimum_required(VERSION 3.5)

project(CAlgo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(HEADER_FILES algo_utils.h algo_sort.h)

add_executable(CAlgo main.cpp ${HEADER_FILES})
target_include_directories(CAlgo PRIVATE ${CMAKE_CURRENT_LIST_DIR})
