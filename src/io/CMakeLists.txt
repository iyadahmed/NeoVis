set(SRC
    io.h
    io.c
)

add_subdirectory(jpgio)
add_library(io ${SRC})
target_link_libraries(io jpgio)
target_include_directories(io PUBLIC .)