cmake_minimum_required(VERSION 3.2)
project(io C)

set(SOURCE_FILES
    io.h
    io.c
)

add_library(io SHARED STATIC ${SOURCE_FILES})

install(TARGETS io DESTINATION ${NEOVIS_INSTALL_LIB_DIR})
install(FILES io.h DESTINATION ${NEOVIS_INSTALL_INCLUDE_DIR})
