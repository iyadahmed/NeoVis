set(SRC
    image.h
    image.c
)

add_library(image ${SRC})
target_include_directories(image PUBLIC .)