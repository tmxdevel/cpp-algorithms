cmake_minimum_required(VERSION 3.5)

project(CAlgo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#find_package(SDL2 REQUIRED)

set(HEADER_FILES algo_utils.h
    algo_sort.h
    algo_structures.h
    algo_2d.h
    testing/bechtimer.h
    testing/algobenchs.h
    data_structures/linked_list.h
    data_structures/cyclic_array.h)
set(SOURCE_FILES
    testing/bechtimer.cpp
    testing/algobenchs.cpp)

add_executable(CAlgo main.cpp ${HEADER_FILES} ${SOURCE_FILES})
target_include_directories(CAlgo PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/testing
    ${CMAKE_CURRENT_LIST_DIR}/data_structures
    ${SDL2_INCLUDE_DIRS})
target_link_libraries(CAlgo SDL2)

install(TARGETS CAlgo DESTINATION ${CMAKE_CURRENT_LIST_DIR}/build)
install(DIRECTORY datasets DESTINATION ${CMAKE_CURRENT_LIST_DIR}/build)
