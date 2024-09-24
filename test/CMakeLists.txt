cmake_minimum_required(VERSION 3.15)

add_compile_options(-std=c++11 -Wall)

set(CMAKE_BUILD_TYPE "Debug")

project(test_program)

aux_source_directory(../utils UTILS_LIST)


add_executable(${PROJECT_NAME} ${UTILS_LIST} test_sort.cpp)
# add_executable(${PROJECT_NAME} ${UTILS_LIST} test_myLinkedList.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ../include)
