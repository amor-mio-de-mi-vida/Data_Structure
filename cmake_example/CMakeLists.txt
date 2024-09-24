cmake_minimum_required(VERSION 3.15)

# set the project name
project(Tutorial VERSION 1.0)

add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)


# should we use our own math functions
option(USE_MYMATH "Use tutorial provided math implementation" ON)

configure_file(TutorialConfig.h.in TutorialConfig.h)

# add the MathFunctions library
if(USE_MYMATH)
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions)
    # list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/MathFunctions)
endif()

SET(SRC_LIST tutorial.cpp)

# add the executable
add_executable(${PROJECT_NAME} ${SRC_LIST})


target_link_libraries(${PROJECT_NAME} PUBLIC ${EXTRA_LIBS} tutorial_compiler_flags)

target_include_directories(${PROJECT_NAME} PUBLIC
                           ${PROJECT_BINARY_DIR}
                        #    ${EXTRA_INCLUDES}
                           )