set(SOURCE_FILES
    common.h
    common.c
)

add_library(common SHARED STATIC ${SOURCE_FILES})
target_include_directories(common PUBLIC .)