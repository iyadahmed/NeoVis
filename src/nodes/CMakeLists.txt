set(SOURCE_FILES
    nodes.h
    nodes.c
)

add_library(nodes SHARED STATIC ${SOURCE_FILES})
target_include_directories(nodes PUBLIC .)