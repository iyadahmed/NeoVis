set(SRC
    nodes.h
    nodes.c

    add/add.c
    add/add.h
)

add_library(nodes ${SRC})
target_include_directories(nodes PUBLIC .)
target_include_directories(nodes PRIVATE add)