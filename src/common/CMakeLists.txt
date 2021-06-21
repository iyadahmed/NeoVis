set(SRC
    common.h
    common.c
)

add_library(common ${SRC})
target_include_directories(common PUBLIC .)