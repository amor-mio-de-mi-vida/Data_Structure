cmake_minimum_required(VERSION 3.15)

add_compile_options(-std=c++11 -Wall -O2)

# set the project name
project(main)

# 利用变量来表示多个源文件
set(SRC_LIST main.cpp)

aux_source_directory(./utils UTILS_LIST)

# add the executable
add_executable(${PROJECT_NAME} ${SRC_LIST} ${UTILS_LIST})

target_include_directories(${PROJECT_NAME} PUBLIC include)
