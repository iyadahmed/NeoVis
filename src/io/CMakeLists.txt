set(SOURCE_FILES
    io.h
    io.c
)

add_subdirectory(jpgio)
add_library(io ${SOURCE_FILES})
target_link_libraries(io jpgio)
target_include_directories(io PUBLIC .)