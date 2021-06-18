set(SOURCE_FILES
    image.h
    image.c
)

add_library(image ${SOURCE_FILES})
target_include_directories(image PUBLIC .)