set(SOURCE_FILES
    nodes.h
    nodes.c
)

add_library(nodes ${SRC})
target_include_directories(nodes PUBLIC .)