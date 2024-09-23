aux_source_directory(. SRC_LIST)

add_library(utils ${SRC_LIST})

target_include_directories(${PROJECT_NAME} PUBLIC include)