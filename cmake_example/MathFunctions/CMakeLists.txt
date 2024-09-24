add_library(MathFunctions mysqrt.cpp)

target_link_libraries(PUBLIC tutorial_compiler_flags)

target_include_directories(MathFunctions
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} tutorial_compiler_flags)
